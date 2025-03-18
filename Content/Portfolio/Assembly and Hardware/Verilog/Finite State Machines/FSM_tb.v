//`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`
//	  File:   FSM_tb.v
//
// 	 Author: Clayton Seelenmayer
//
// 	 Date:   Nov 7th 2021
//
// 	 Behavior:
// 	     This program contains the test-bench implementations for demonstrating
// 	         the usage of Mealy and Moore finite state machines.
//
// 	 Compilation:    "iverilog -o FSM.vvp FSM.v"
// 	                 "vvp FSM.vvp"
//   	               "gtkwave FSM.vcd"
//`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`


`timescale 1ns/1ns
`include "Latches.v"


//`^*~-~*^`^*~-~*^` Moore-Type FSM `^*~-~*^`^*~-~*^`
module MooreTypeFSM_tb();
	reg clk = 0;
	reg w;
	reg Resetn;
	wire z;
	MooreTypeFSM c2(clk, w, Resetn, z);
	always begin
		clk = ~clk;
		#5;
	end
	initial begin
		$dumpfile("FSM_tb.vcd");
		$dumpvars(0,MooreTypeFSM_tb);
		Resetn = 0; #10;
		w = 1; #10; w = 0; #10;
		w = 1; #10; w = 1; #10;
		w = 0; #10; w = 0; #10;
		w = 1; #10; w = 1; #10;
		w = 1; #10; w = 0; #10;
		w = 1; #10; w = 1; #10;
		Resetn = 1; #10;
		w = 1; #10; w = 0; #10;
		w = 1; #10; w = 1; #10;
		w = 0; #10; w = 0; #10;
		w = 1; #10; w = 1; #10;
		w = 1; #10; w = 0; #10;
		w = 1; #10; w = 1; #10;
		$finish;
	end
endmodule


//`^*~-~*^`^*~-~*^` Mealy-Type FSM `^*~-~*^`^*~-~*^`
module MealyTypeFSM_tb();
	reg clk = 0;
	reg w;
	reg Resetn = 0;
	wire z;
	SimpleMealyModule c4(clk, w, Resetn, z);
	always begin
		clk = ~clk;
		#5;
	end
	initial begin
		$dumpfile("FSM_tb.vcd");
		$dumpvars(0,MealyTypeFSM_tb);
		Resetn = 0; #10;
		w = 1; #10; w = 0; #10;
		w = 1; #10; w = 1; #10;
		w = 0; #10; w = 0; #10;
		w = 1; #10; w = 1; #10;
		w = 1; #10; w = 0; #10;
		w = 1; #10; w = 1; #10;
		Resetn = 1; #10;
		w = 1; #10; w = 0; #10;
		w = 1; #10; w = 1; #10;
		w = 0; #10; w = 0; #10;
		w = 1; #10; w = 1; #10;
		w = 1; #10; w = 0; #10;
		w = 1; #10; w = 1; #10;
		$finish;
	end
endmodule