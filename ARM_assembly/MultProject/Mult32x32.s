		;INITIALISATION
		
		MOV		R0, #12
		MOV		R1, #4
		MOV		R2, R0
		MOV		R3, #0
		MOV		R5, #0
		MOV		R6, #32
		
		;CODE
		
MULT		AND		R4, R2, #1 ;movs LSB
		
		CMP		R4, R5 ;Compares current and prev bit
		ADDLO	R3, R3, R1 ;adds if 0 1
		SUBHI	R3, R3, R1 ;sub if 1 0
		MOV		R5, R4
		
		MOVS		R3, R3, ASR #1
		MOV		R2, R2, RRX
		
		SUBS		R6, R6, #1
		BNE		MULT
