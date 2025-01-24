//`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`
//	File:	FSM.v
//
//	Author:	Clayton Seelenmayer
//
//	Date:	Nov 7th 2021
//
//	Behavior:
//		This program contains the implementations for demonstrating
//			the Mealy and Moore styled finite state machines.
//
//	Compilation:	"iverilog -o FSM.vvp FSM.v"
//					"vvp FSM.vvp"
//					"gtkwave FSM.vcd"
//`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`^*~-~*^`


//`^*~-~*^`^*~-~*^` Simple Moore Module `^*~-~*^`^*~-~*^`
module SimpleMooreModule(
	input wire clk,
	input wire w,
	input wire Resetn,
	output reg z
);
	reg [1:0] y, Y;			//present and next state
	parameter A=2'b00, B=2'b01, C=2'b10;
	always @(w,y) begin
		case (y)
			A: if (w) Y=B;
				else Y=A;
			B: if (w) Y=C;
				else Y=A;
			C: if (w) Y=C;
				else Y=A;
			default: Y=2'bxx;
		endcase
	end
	always @(y) begin
		if (y==C) z = 1;
		else z = 0;
	end
	always @(negedge Resetn, posedge clk) begin
		#10;
		if (Resetn==0) y <= A;
		else y <= Y;
	end
endmodule


//`^*~-~*^`^*~-~*^` Moore-Type FSM `^*~-~*^`^*~-~*^`
module MooreTypeFSM(
	input wire clk,
	input wire w,
	input wire Resetn,
	output reg z
);
	reg [2:0] y, Y;
	parameter A=3'b000, B=3'b001, C=3'b010, D=3'b011, E=3'b100, F=3'b101;
	always @(w,y) begin
		case (y)
			A: if (w) Y=B;
				else Y=A;
			B: if (w) Y=C;
				else Y=D;
			C: if (w) Y=C;
				else Y=E;
			D: if (w) Y=F;
				else Y=A;
			E: if (w) Y=F;
				else Y=A;
			F: if (w) Y=C;
				else Y=D;
			default: Y=3'bxxx;
		endcase
	end
	always @(y) begin
		if (y==E | y==F) z = 1;
		else z = 0;
	end
	always @(negedge Resetn, posedge clk) begin
		#10;
		if (Resetn==0) y <= A;
		else y <= Y;
	end
endmodule


//`^*~-~*^`^*~-~*^` Simple Mealy Module `^*~-~*^`^*~-~*^`
module SimpleMealyModule(
	input wire clk,
	input wire w,
	input wire Resetn,
	output reg z
);
	reg y, Y;
	parameter A=1'b0, B=1'b1;
	always @(w,y) begin
		case (y)
			A: if (w) begin 
				Y=B;
				z=0;
			end
			else begin
				Y=A;
			end
			B: if (w) begin
				Y=B;
				z=1;
			end
			else begin
				Y=A;
				z=0; 
			end
		endcase
	end
	always @(negedge Resetn, posedge clk) begin
		#10;
		if (Resetn==0)  y <= A;
		else y <= Y;
	end
endmodule


//`^*~-~*^`^*~-~*^` Mealy-Type FSM `^*~-~*^`^*~-~*^`
module MealyTypeFSM( input wire clk, input wire w, input wire Resetn, output reg z);
	reg [2:0] y, Y;
	parameter A=3'b000, B=3'b001, C=3'b010, D=3'b011, E=3'b100, F=3'b101;
	always @(w,y) begin
		case (y)
			A: if (w) begin 
				Y=B; z=0;
			end
			else begin
				Y=A; z=0;
			end
			B: if (w) begin
				Y=C; z=0;
			end
			else begin
				Y=D; z=0; 
			end
			C: if (w) begin
				Y=C; z=0;
			end
			else begin
				Y=A; z=1; 
			end
			D: if (w) begin
				Y=B; z=1;
			end
			else begin
				Y=A; z=0;
			end
		endcase
	end
	always @(negedge Resetn, posedge clk) begin
		#10;
		if (Resetn==0)  y <= A;
		else y <= Y;
	end
endmodule