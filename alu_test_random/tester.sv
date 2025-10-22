`timescale 1ns/1ps

module tester;
  localparam int WIDTH = 8;

  typedef enum logic [2:0] {
    ALU_ADD = 3'b000,
    ALU_SUB = 3'b001,
    ALU_AND = 3'b010,
    ALU_OR  = 3'b011,
    ALU_XOR = 3'b100
  } alu_op_e;

  logic [WIDTH-1:0] a, b, y;
  alu_op_e          op;
  logic             zero, carry, overflow;

  alu #(.WIDTH(WIDTH)) dut (.a(a), .b(b), .op(op), .y(y), .zero(zero), .carry(carry), .overflow(overflow));

  class alu_txn;
    rand bit [WIDTH-1:0] ra, rb;
    rand alu_op_e        rop;
    constraint c_ops { rop inside {ALU_ADD, ALU_SUB, ALU_AND, ALU_OR, ALU_XOR}; }
    constraint c_rng { ra < 8'd200; rb < 8'd200; }
  endclass

  alu_txn t;

  function automatic [WIDTH-1:0] model(input alu_op_e op_i, input [WIDTH-1:0] a_i, input [WIDTH-1:0] b_i);
    case (op_i)
      ALU_ADD: return a_i + b_i;
      ALU_SUB: return a_i - b_i;
      ALU_AND: return a_i & b_i;
      ALU_OR : return a_i | b_i;
      ALU_XOR: return a_i ^ b_i;
      default: return '0;
    endcase
  endfunction

  initial begin
    $dumpfile("wave.vcd");
    $dumpvars(0, tester);
    t = new();
    repeat (20) begin
      bit ok = bit'(t.randomize());
      if (!ok) $fatal(1, "randomize failed");
      a  = t.ra;
      b  = t.rb;
      op = t.rop;
      #1;
      if (y !== model(op, a, b))
        $display("FAIL op=%0d a=%0d b=%0d -> y=%0d exp=%0d z=%0b c=%0b v=%0b",
                 op, a, b, y, model(op,a,b), zero, carry, overflow);
      else
        $display("PASS op=%0d a=%0d b=%0d -> y=%0d z=%0b c=%0b v=%0b",
                 op, a, b, y, zero, carry, overflow);
    end
    $finish;
  end
endmodule

module alu #(
  parameter int WIDTH = 8
)(
  input  logic [WIDTH-1:0] a,
  input  logic [WIDTH-1:0] b,
  input  logic [2:0]       op,
  output logic [WIDTH-1:0] y,
  output logic             zero,
  output logic             carry,
  output logic             overflow
);
  logic [WIDTH:0] add_ext;
  logic [WIDTH:0] sub_ext;

  always_comb begin
    y        = '0;
    carry    = 1'b0;
    overflow = 1'b0;
    add_ext  = '0;
    sub_ext  = '0;

    unique case (op)
      3'b000: begin // ADD
        add_ext  = {1'b0, a} + {1'b0, b};
        y        = add_ext[WIDTH-1:0];
        carry    = add_ext[WIDTH];
        overflow = (a[WIDTH-1] == b[WIDTH-1]) && (y[WIDTH-1] != a[WIDTH-1]);
      end
      3'b001: begin // SUB
        sub_ext  = {1'b0, a} - {1'b0, b};
        y        = sub_ext[WIDTH-1:0];
        carry    = ~sub_ext[WIDTH]; // carry=1 => no borrow
        overflow = (a[WIDTH-1] != b[WIDTH-1]) && (y[WIDTH-1] != a[WIDTH-1]);
      end
      3'b010: y = a & b;
      3'b011: y = a | b;
      3'b100: y = a ^ b;
      default: y = '0;
    endcase
  end

  assign zero = (y == '0);
endmodule
