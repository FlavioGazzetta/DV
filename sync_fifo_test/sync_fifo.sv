module sync_fifo #(
  parameter DATA_WIDTH = 8,
  parameter DEPTH = 16,
  parameter ADDR_WIDTH = $clog2(DEPTH)
)(
  input  logic                 clk,
  input  logic                 rstn,      // active low reset
  input  logic                 wr_en,     // write enable
  input  logic                 rd_en,     // read enable
  input  logic [DATA_WIDTH-1:0] din,
  output logic [DATA_WIDTH-1:0] dout,
  output logic                 full,
  output logic                 empty
);

  // FIFO memory
  logic [DATA_WIDTH-1:0] mem [0:DEPTH-1];

  // Pointers
  logic [ADDR_WIDTH:0] wr_ptr, rd_ptr;  // 1 extra bit for full/empty detection

  // Write logic
  always_ff @(posedge clk or negedge rstn) begin
    if (!rstn)
      wr_ptr <= '0;
    else if (wr_en && !full) begin
      mem[wr_ptr[ADDR_WIDTH-1:0]] <= din;
      wr_ptr <= wr_ptr + 1;
    end
  end

  // Read logic
  always_ff @(posedge clk or negedge rstn) begin
    if (!rstn) begin
      rd_ptr <= '0;
      dout   <= '0;
    end else if (rd_en && !empty) begin
      dout   <= mem[rd_ptr[ADDR_WIDTH-1:0]];
      rd_ptr <= rd_ptr + 1;
    end
  end

  // Full and empty flags
  assign full  = ( (wr_ptr[ADDR_WIDTH] != rd_ptr[ADDR_WIDTH]) && (wr_ptr[ADDR_WIDTH-1:0] == rd_ptr[ADDR_WIDTH-1:0]) );

  assign empty = (wr_ptr == rd_ptr);

endmodule
