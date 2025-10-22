`timescale 1ns/1ps

module tester;

    localparam int DATA_W = 8;
    localparam int DEPTH  = 16;

    logic clk, rstn;
    logic rstn_sync;
    logic wr_en, rd_en;
    logic [DATA_W-1:0] din, dout;
    logic full, empty;

    logic [DATA_W-1:0] exp_q[$];

    initial clk = 0;
    always #5 clk = ~clk;

    always_ff @(posedge clk or negedge rstn)
        if (!rstn) rstn_sync <= 1'b0;
        else       rstn_sync <= 1'b1;

    sync_fifo #(.DATA_WIDTH(DATA_W), .DEPTH(DEPTH)) dut (
        .clk(clk),
        .rstn(rstn),
        .wr_en(wr_en),
        .rd_en(rd_en),
        .din(din),
        .dout(dout),
        .full(full),
        .empty(empty)
    );

    task automatic reset_dut();
        rstn = 0; wr_en = 0; rd_en = 0; din = '0;
        repeat (2) @(posedge clk);
        rstn = 1;
        repeat (1) @(posedge clk);
        assert (empty) else $fatal("empty not high after reset");
        assert (!full) else $fatal("full high after reset");
        exp_q.delete();
    endtask

    task automatic do_write(input logic [DATA_W-1:0] val);
        bit allow;
        @(posedge clk);
        allow = !full;
        if (allow) begin
        din   = val;
        wr_en = 1;
        end else begin
        wr_en = 0;
        end
        @(posedge clk);
        wr_en = 0;
        if (allow) exp_q.push_back(val);
    endtask

    task automatic do_read();
        bit allow;
        @(posedge clk);
        allow = !empty;
        if (allow) rd_en = 1; else rd_en = 0;
        @(posedge clk);
        rd_en = 0;
        if (allow) begin
        logic [DATA_W-1:0] exp = exp_q.pop_front();
        if (dout !== exp) $fatal("DATA MISMATCH: got=%0d exp=%0d", dout, exp);
        end
    endtask

    always @(posedge clk) if (rstn_sync) begin
        assert (!(full  && wr_en)) else $error("Write attempted while full");
        assert (!(empty && rd_en)) else $error("Read  attempted while empty");
        assert (!(full && empty))  else $fatal("Both full and empty high");
    end

    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, tester);

        reset_dut();

        for (int i = 0; i < DEPTH; i++) begin
        do_write(i[DATA_W-1:0]);
        end
        assert (full)  else $fatal("Should be full after %0d writes", DEPTH);
        assert (!empty);

        do_write(8'hAA);
        assert (full);

        for (int i = 0; i < DEPTH/2; i++) begin
        do_read();
        end
        assert (!full);

        for (int i = 0; i < DEPTH*2; i++) begin
        fork
            do_write(8'(i+100));
            do_read();
        join
        end

        while (!empty) do_read();
        assert (empty) else $fatal("Should be empty at the end");

        repeat (200) begin
        bit do_w = bit'($urandom_range(0,1));
        bit do_r = bit'($urandom_range(0,1));
        if (full)  do_w = 0;
        if (empty) do_r = 0;
        if (do_w) do_write($urandom[DATA_W-1:0]);
        if (do_r) do_read();
        end

        while (!empty) do_read();
        $display("TB PASS");
        $finish;
    end

endmodule
