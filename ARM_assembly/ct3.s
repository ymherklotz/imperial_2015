		CMP		R1, #1
		BEQ		LOOP3
		MOV		R2, R1
LOOP1	SUB		R2, R2, #2
		MOV		R3, R2
		MOV		R0, #0
LOOP2	ADD		R0, R0, R1
		SUB		R3, R3, #1
		CMP		R3, #0
		BNE		LOOP2
		MOV		R1, R0
		CMP		R2, #1
		BNE		LOOP1
LOOP3	MOV		R0, R1
