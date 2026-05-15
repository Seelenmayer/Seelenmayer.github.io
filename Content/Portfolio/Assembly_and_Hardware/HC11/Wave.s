;============================================================================================\
;	File:
       .file "wave.s" 
;	Author:
;		Clayton Seelenmayer
;	Date:
;		Nov 28th 2018
;	Behaviour:
;		Creates a 30% pulse-width duty-cycle
;			modulation signal by interrupts on
;			the HC11.
;	Assumptions:
;			none
;	Board:
;		CME11-E9-EVBU (with the PW link HACK)
;		M86HC11E architecture
;============================================================================================/


;--------------------------------------------------------------------------------------------\
;	Initializations
;--------------------------------------------------------------------------------------------/

.sect .text
;.global _start

set regbase,	0x1000		;Displacement base.
set porta,		0x00		;Port A.

set tcnt,		0x0e		;Time counter.
set tflg1,		0x23		;1st timer flag.
set tctl1,		0x20		;Set pin control logic.
set toc2,		0x18		;Timer output capture.
set tmsk1,		0x22		;Arm the interrupt.

set toggle,		0x40		;Toggles high/low states.
set clear,		0x40		;Clear

set oc2,			0x40		;Timer flag pin.
set oc2i,		0x40		;Timer flag interrupt.

set Jump,		0x7e		;Jump code.
set toc2a,		0xdc		;Jump table.
set toc2ptr,	0xdd		;Pointer into jump table.

set highTicks,	600			;300 us
set lowTicks,	1400		;700 us

set High,		1			;High wave
set Low,			0			;Low wave


;-------------------------------------------------------------------------------------------\
;	Behaviour:
;		Loads Jump table, sets up registers,
;		states, and interrupts.
;	Assumptions:
;		none
;	Register and Memory Usage:
;		Precondition:
;		Postcondition:
;			High or low wave output.
;		Destroys:
;			none
;-------------------------------------------------------------------------------------------/

_start:
					lds #_stack				;Stack ptr.
					sei						;Disable interrupts.

					;Setup Jump Table
					ldaa #Jump				;Load jump code and store in toc2 jump table.
					staa toc2a
					ldx #highToLow			;Load high state wave interrupt service routine and store into jump table.
					stx toc2ptr

					;Setup registers, states, and pins.
					ldx  #regbase			;Load register offset.
					ldaa #High				;Set state to high and save state.
					staa StateVar
					bset porta,x oc2		;Set oc2 pin to high (PA6).
					ldaa #toggle			;Set successful compare action to toggle (see HC11 manual p365).
					staa tctl1,x			;Pin control.

					;Setup clock and next interrupt.
					ldd tcnt,x				;Input clock into D.
					addd #highTicks		;Add the high ticks timer offset to the clock for the next interrupt.
					std toc2,x				;Store the next interrupt that will occur into toc2.
					ldaa #clear				;Clear the timer flag
					staa tflg1,x
					cli						;Enable interrupts
					bset tmsk1,x oc2i		;Enable toc2 interrupts


;-------------------------------------------------------------------------------------------\
;	Behaviour: 
;		Interrupt service routine loop
;	Assumptions:
;		none
;	Restriction:
;		none
;	Register and Memory Usage:
;		Precondition:
;		Postcondition:
;		Destroys:
;			none
;-------------------------------------------------------------------------------------------/

loop:
					jmp  loop


;-------------------------------------------------------------------------------------------\
;	Behaviour:
;		Sets wave to low or branches to lowToHigh
;			if the state is low.
;	Assumptions:
;		none
;	Restriction:
;		none
;	Register and Memory Usage:
;		Precondition:
;		Postcondition:
;			Sets state variable to high
;		Destroys:
;			D register
;-------------------------------------------------------------------------------------------/

;Low Wave State
highToLow:
					ldaa StateVar			;Decrement state from high (1) to low (0).
					deca
					beq  lowToHigh			;Branch if the state is low. Otherwise its high.
					ldd  toc2,x				;Load oc2 to low and after 700us toggle state.
					addd #highTicks
					std  toc2,x
					ldaa #High				;Set the state variable to high.
					staa StateVar
					jmp  returnFunc		;Return


;-------------------------------------------------------------------------------------------\
;	Behaviour:
;		Sets wave to high.
;	Assumptions:
;		none
;	Restriction:
;		none
;	Register and Memory Usage:
;		Precondition:
;		Postcondition:
;			Sets state variable to low
;		Destroys:
;			D register
;-------------------------------------------------------------------------------------------/

lowToHigh:
					ldd  toc2,x				;Toggle oc2 to High after 300us.
					addd #lowTicks
					std  toc2,x
					ldaa #Low				;Update the State variable to Low.
					staa StateVar


;-------------------------------------------------------------------------------------------\
;	Behaviour:
;		Return function routine.
;	Assumptions:
;		none
;	Restriction:
;		none
;	Register and Memory Usage:
;		Precondition:
;		Postcondition:
;			Return to caller.
;		Destroys:
;			oc2f timer flag.
;-------------------------------------------------------------------------------------------/

returnFunc:
					ldaa #clear			;Clear oc2f timer flag and return.
					staa tflg1,x
					rti


;-------------------------------------------------------------------------------------------\
;	Variables
;-------------------------------------------------------------------------------------------/
StateVar: .byte 1
#set up dummy frame pointer
.global _.frame
_.frame: .word
.end