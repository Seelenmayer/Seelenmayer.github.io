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


//`^*~-~*^`^*~-~*^` SR Latch with NOR Gates `^*~-~*^`^*~-~*^`
module SRLatchNor_tb();
	reg s, r;
	wire q, q_n;
	SRLatchNor c1(s, r, q, q_n);
	initial begin
		$dumpfile("Latches_tb.vcd");
		$dumpvars(0, SRLatchNor_tb);
		{s,r} = 2'b00; #10;
		{s,r} = 2'b01; #10;
		{s,r} = 2'b10; #10;
		{s,r} = 2'b11; #10;
		$display("Test completed");
	end
endmodule

//`^*~-~*^`^*~-~*^` Gated D Latch with Enable `^*~-~*^`^*~-~*^`
module GatedDLatch_tb();
	reg clk = 0;
	reg d = 0;
	reg en = 0;
	wire q;
	wire q_n;
	GatedDLatch c2(clk, d, en, q, q_n);
	always begin
		clk = ~clk; #5;
	end
	initial begin
		$dumpfile("Latches_tb.vcd");
		$dumpvars(0, GatedDLatch_tb);
		en = 0; #15;
		d = 0; #15;
		d = 1; #15;
		d = 0; #15;
		en = 1; #15;
		d = 0; #15;
		d = 1; #15;
		d = 0; #15;
		$display("Test completed");
		$finish;
	end
endmodule


//`^*~-~*^`^*~-~*^` Gated D Latch with Reset `^*~-~*^`^*~-~*^`
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


//`^*~-~*^`^*~-~*^` Asynchronous Up Counter `^*~-~*^`^*~-~*^`
module upcount_tb #(parameter N=4)();
	reg clk = 0;
	reg reset;
	reg en;
	wire[N-1:0] q;
	upcount c4(clk, reset, en, q);
	always begin
		clk = ~clk; #4;
	end
	initial begin
		$dumpfile("Latches_tb.vcd");
		$dumpvars(0, upcount_tb);
		en = 0; #20;
		reset = 0; #20;
		reset = 1; #20;
		reset = 0; #20;
		en = 1; #20;
		reset = 0; #20;
		reset = 1; #20;
		reset = 0; #20;
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