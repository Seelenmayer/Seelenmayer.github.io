//`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`
//	File:	Latches.v
//
//	Author:	Clayton Seelenmayer
//
//	Date:	Nov 17th 2021
//
//	Behavior:
//		This program contains the implementations for demonstrating
//			the usage of data latches such as:
//				- Gated D Latches with Reset.
//				- Johnson Counter.
//
//	Compilation:	"iverilog -o Latches.vvp Latches.v"
//					"vvp Latches.vvp"
//					"gtkwave Latches.vcd"
//`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`


//`^*~-~*^`^*~-~*^` DFlipflop `^*~-~*^`^*~-~*^`
module DFlipflop(
	input wire clk,
	input wire d,
	input wire reset_n,
	output wire q
);

wire w11, w21, w12, w22, w13, w23, q_n;

not(d_n, d);
not(clk_n, clk);
not(clk_n_n, clk_n);

//Column 1
nand(w11, d, reset_n, clk_n);
nand(w21, clk_n, d_n);

//Column 2
nand(w12, w11, w22);
nand(w22, w12, w21, reset_n);

//Column 3
nand(w13, w12, reset_n, clk_n_n);
nand(w23, clk_n_n, w22);

//Column 4
nand(q, w13, q_n);
nand(q_n, q, w23, reset_n);

endmodule


//`^*~-~*^`^*~-~*^` Johnson Counter `^*~-~*^`^*~-~*^`
module JohnsonCounter #(parameter N = 8)(reset_n, clk, q);
	input wire reset_n;
	input wire clk;
	output wire [N-1:0] q;
	genvar i;
	generate
		for (i=0 ; i<N ; i=i+1) begin
			if (i == 0)
				DFlipflop stage0(clk, ~q[N-1], reset_n, q[i]);
			else
				DFlipflop stage1(clk, q[i-1], reset_n, q[i]);
		end
	endgenerate
endmodule