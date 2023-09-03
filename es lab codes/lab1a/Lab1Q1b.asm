	AREA RESET,DATA,READONLY
	EXPORT __Vectors
	
__Vectors 
	DCD 0X10010000
	DCD Reset_Handler
	
	ALIGN
	AREA CODE_SEG, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=SRC+(len-1)*4
	LDR R1,=SRC+(len-1+shift)*4
	MOV R3,#10
UP
	LDR R2,[R0],#-4
	STR R2,[R1],#-4
	SUBS R3,#1
	BNE UP
STOP B STOP
len equ 10
shift equ 2
	AREA DATA_SEG,READWRITE
SRC DCD 0,0,0,0,0,0,0,0,0,0,0,0
	END