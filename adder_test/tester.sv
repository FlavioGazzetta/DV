module adder(
    input  logic a,
    input  logic b,
    output logic z
);
    assign z = a + b;
endmodule


module tester;

    logic [3:0] a, b;
    logic [3:0] z;

    // 4 independent 1-bit adders (each drives one bit of z)
    adder b0 (.a(a[0]), .b(b[0]), .z(z[0]));
    adder b1 (.a(a[1]), .b(b[1]), .z(z[1]));
    adder b2 (.a(a[2]), .b(b[2]), .z(z[2]));
    adder b3 (.a(a[3]), .b(b[3]), .z(z[3]));

    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, tester);

        a = 4;   // 0100
        b = 1;   // 0001
        #1;

        $display("a=%0d b=%0d z=%0d", a, b, z);
        $finish;
    end
endmodule

