		;4.1
		
		;		MOV		R0, #0xFFFFFFFF
		;		MOV		R1, #0xFFFFFFFF
		;		MOV		R2, #0x0000008B
		;
		;		ADDS		R0, R0, #1
		;		BCS		CARRY1
		;		B		EXIT
		;CARRY1	ADCS		R1, R1, #0
		;		BCS		CARRY2
		;		B		EXIT
		;CARRY2	ADC		R2, R2, #0
		;EXIT
		
		;4.2
		
		;		MOV		R0, #0x00000000
		;		MOV		R1, #0x00000000
		;		MOV		R2, #0x0000008B
		;
		;		SUBS		R0, R0, #1
		;		BCC		NCAR1
		;		B		EXIT
		;NCAR1	SBCS		R1, R1, #0
		;		BCC		NCAR2
		;		B		EXIT
		;NCAR2	SBC		R2, R2, #0
		;
		;EXIT
		
		;4.3
		
		;MOV		R2, #0xFFFFFFFF
		;MOV		R3, R2
		;MOV		R4, R2
		;MOV		R5, R4
		;MOV		R11, #0xFFFFFFFF
		;ADDS	R11, R11, #1
		;
		;ADDS	R0, R2, R4
		;ADCS	R1, R3, R5
		;MOVCS	R6, #1
		;MOVCC	R6, #0
		
		;4.4
		
		;MOV		R0, #-254
		;MOV		R1, #254
		;
		;ADDS	R2, R1, R0
		;MOVVS	R3, #1
		;MOVVC	R3, #0
		;MOVCS	R4, #1
		;MOVCC	R4, #0
		
		;4.5
		
		;		MOV		R0, #0xFFFFFFFF
		;		MOV		R1, #0xBFFFFFFF
		;		MOV		R2, #1
		;		MOV		R6, #7
		;
		;MULT	ADDS		R3, R3, R0
		;		ADCS		R4, R4, R1
		;		ADCS		R5, R5, R2
		;		SUB		R6, R6, #1
		;		CMP		R6, #0
		;		BNE		MULT
		
		;4.6
		
		;MOV		R0, #0xFB
		;MOV		R0, R0, LSL #22
		;MOVS	R1, R0, LSL #1
		;BPL		POS
		;
		;MVN		R2, R0
		;MVN		R3, R1
		;ADD		R2, R2, #1
		;B		EXIT
		;POS		MOV		R2, R0
		;MOV		R3, R1
		;EXIT
		
		;4.7
		
		;MOV		R0, #0xFFFFFFFF
		;MOV		R1, #0xFF
		;
		;MOVS	R2, R0, LSL #1
		;MOV		R3, R1, LSL #1
		;ADDCS	R3, R3, #1
		
		;4.8
		
		;MOV		R0, #0xFFFFFFFF
		;MOV		R1, #0xFFFFFFFF
		;MOV		R2, #0xFF
		;
		;MOVS	R5, R2, RRX
		;MOVS	R4, R1, RRX
		;MOVS	R3, R0, RRX
		
		;4.9
		
		;MOV		R0, #0xA8000000
		;MOV		R1, #0
		;MOV		R5, #5
		;
		;MOV		R3, R1, LSL #5
		;MOV		R2, R0, LSL #5
		;LOOP	MOVS		R0, R0, LSL #1
		;MOV		R4, #0
		;MOVCS	R4, #1
		;SUBS	R5, R5, #1
		;MOV		R4, R4, LSL R5
		;ADD		R3, R4, R3
		;BNE		LOOP
		
		;4.10
		
		;		MOV		R0, #0xA3
		;		MOV		R2, #10
		;		MOV		R0, R0, LSL #22
		;LOOP	MOVS		R0, R0, LSL #1
		;		MOVCS	R3, #1
		;		MOVCC	R3, #0
		;		MOV		R1, R1, LSL #1
		;		ADD		R1, R3, R1
		;		SUBS		R2, R2, #1
		;		BNE		LOOP
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
