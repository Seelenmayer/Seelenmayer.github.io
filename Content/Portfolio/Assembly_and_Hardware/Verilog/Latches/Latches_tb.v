//`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`
//	File:	Latches_tb.v
//
//	Author:	Clayton Seelenmayer
//
//	Date:	Nov 17th 2021
//
//	Behavior:
//		This program contains the implementations for supplying
//			test data information about latches to GTKWave.
//
//	Compilation:	"iverilog -o Latches.vvp Latches.v"
//					"vvp Latches.vvp"
//					"gtkwave Latches.vcd"
//`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`


`timescale 1ns/1ns
`include "Latches.v"


//`^*~-~*^`^*~-~*^` DFlipflop `^*~-~*^`^*~-~*^`
module DFlipflop_tb();
	reg clk = 0;
	reg d = 0;
	reg reset_n = 0;
	wire q;
	DFlipflop c3(clk, d, reset_n, q);
	always begin
		clk = ~clk; #10;
	end
	initial begin
		$dumpfile("Latches_tb.vcd");
		$dumpvars(0, DFlipflop_tb);
		reset_n = 0; #35;
		d = 0; #35;
		d = 1; #35;
		d = 0; #35;
		reset_n = 1; #35;
		d = 0; #35;
		d = 1; #35;
		d = 0; #35;
		$display("Test completed");
		$finish;
	end
endmodule


//`^*~-~*^`^*~-~*^` Johnson Counter `^*~-~*^`^*~-~*^`
module JohnsonCounter_tb #(parameter N=8)();
	reg clk = 0;
	reg reset_n;
	wire[N-1:0] q;
	JohnsonCounter c5(reset_n, clk, q);
	always begin
		clk = ~clk; #4;
	end
	initial begin
		$dumpfile("Latches_tb.vcd");
		$dumpvars(0, JohnsonCounter_tb);
		reset_n = 0; #60;
		reset_n = 1; #60;
		$display("Test completed");
		$finish;
	end
endmodule