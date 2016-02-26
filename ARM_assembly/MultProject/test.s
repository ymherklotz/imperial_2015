		LDR		R0, =INA
		LDR		R1, =INB
		LDR		R2, =OUTAxB
		BL		SMUL64X64
		END
		
INA		DCD		0x33333333,0x33
INB		DCD		0x44444444,0x44
OUTAxB	FILL		4*4
		;		OUTAxB7		DCD		0XFE3F09B0,0X2829D69,0X913A81B,0X20BD7902
		
SMUL64X64	STMED	R13!, {R0, R4-R12, LR}
		LDR		R3, [R0]
		LDR		R4, [R0, #4]
		LDR		R7, [R1]
		LDR		R8, [R1, #4]
		MOV		R10, #0
		MOV		R11, #7
		AND		R9, R3, #1 ;1
		CMP		R9, R10
		BEQ		CONT1
		MVNHI	R0, R7
		ADDHI	R0, R0, #1
		MVNHI	R12, R8
		MOVLO	R0, R7
		MOVLO	R12, R8
		ADDS		R5, R5, R0
		ADC		R6, R6, R12
CONT1	MOVS		R6, R6, ASR #1
		MOVS		R5, R5, RRX
		MOVS		R4, R4, RRX
		MOVS		R3, R3, RRX
		MOV		R10, R9
MULT		AND		R9, R3, #1 ;2
		CMP		R9, R10
		BEQ		CONT2
		MVNHI	R0, R7
		ADDHI	R0, R0, #1
		MVNHI	R12, R8
		MOVLO	R0, R7
		MOVLO	R12, R8
		ADDS		R5, R5, R0
		ADC		R6, R6, R12
CONT2	MOVS		R6, R6, ASR #1
		MOVS		R5, R5, RRX
		MOVS		R4, R4, RRX
		MOVS		R3, R3, RRX
		MOV		R10, R9
		AND		R9, R3, #1 ;3
		CMP		R9, R10
		BEQ		CONT3
		MVNHI	R0, R7
		ADDHI	R0, R0, #1
		MVNHI	R12, R8
		MOVLO	R0, R7
		MOVLO	R12, R8
		ADDS		R5, R5, R0
		ADC		R6, R6, R12
CONT3	MOVS		R6, R6, ASR #1
		MOVS		R5, R5, RRX
		MOVS		R4, R4, RRX
		MOVS		R3, R3, RRX
		MOV		R10, R9
		AND		R9, R3, #1 ;4
		CMP		R9, R10
		BEQ		CONT4
		MVNHI	R0, R7
		ADDHI	R0, R0, #1
		MVNHI	R12, R8
		MOVLO	R0, R7
		MOVLO	R12, R8
		ADDS		R5, R5, R0
		ADC		R6, R6, R12
CONT4	MOVS		R6, R6, ASR #1
		MOVS		R5, R5, RRX
		MOVS		R4, R4, RRX
		MOVS		R3, R3, RRX
		MOV		R10, R9
		AND		R9, R3, #1 ;5
		CMP		R9, R10
		BEQ		CONT5
		MVNHI	R0, R7
		ADDHI	R0, R0, #1
		MVNHI	R12, R8
		MOVLO	R0, R7
		MOVLO	R12, R8
		ADDS		R5, R5, R0
		ADC		R6, R6, R12
CONT5	MOVS		R6, R6, ASR #1
		MOVS		R5, R5, RRX
		MOVS		R4, R4, RRX
		MOVS		R3, R3, RRX
		MOV		R10, R9
		AND		R9, R3, #1 ;6
		CMP		R9, R10
		BEQ		CONT6
		MVNHI	R0, R7
		ADDHI	R0, R0, #1
		MVNHI	R12, R8
		MOVLO	R0, R7
		MOVLO	R12, R8
		ADDS		R5, R5, R0
		ADC		R6, R6, R12
CONT6	MOVS		R6, R6, ASR #1
		MOVS		R5, R5, RRX
		MOVS		R4, R4, RRX
		MOVS		R3, R3, RRX
		MOV		R10, R9
		AND		R9, R3, #1 ;7
		CMP		R9, R10
		BEQ		CONT7
		MVNHI	R0, R7
		ADDHI	R0, R0, #1
		MVNHI	R12, R8
		MOVLO	R0, R7
		MOVLO	R12, R8
		ADDS		R5, R5, R0
		ADC		R6, R6, R12
CONT7	MOVS		R6, R6, ASR #1
		MOVS		R5, R5, RRX
		MOVS		R4, R4, RRX
		MOVS		R3, R3, RRX
		MOV		R10, R9
		AND		R9, R3, #1 ;8
		CMP		R9, R10
		BEQ		CONT8
		MVNHI	R0, R7
		ADDHI	R0, R0, #1
		MVNHI	R12, R8
		MOVLO	R0, R7
		MOVLO	R12, R8
		ADDS		R5, R5, R0
		ADC		R6, R6, R12
CONT8	MOVS		R6, R6, ASR #1
		MOVS		R5, R5, RRX
		MOVS		R4, R4, RRX
		MOVS		R3, R3, RRX
		MOV		R10, R9
		AND		R9, R3, #1 ;9
		CMP		R9, R10
		BEQ		CONT9
		MVNHI	R0, R7
		ADDHI	R0, R0, #1
		MVNHI	R12, R8
		MOVLO	R0, R7
		MOVLO	R12, R8
		ADDS		R5, R5, R0
		ADC		R6, R6, R12
CONT9	MOVS		R6, R6, ASR #1
		MOVS		R5, R5, RRX
		MOVS		R4, R4, RRX
		MOVS		R3, R3, RRX
		MOV		R10, R9
		AND		R9, R3, #1 ;10
		CMP		R9, R10
		BEQ		CONT10
		MVNHI	R0, R7
		ADDHI	R0, R0, #1
		MVNHI	R12, R8
		MOVLO	R0, R7
		MOVLO	R12, R8
		ADDS		R5, R5, R0
		ADC		R6, R6, R12
CONT10	MOVS		R6, R6, ASR #1
		MOVS		R5, R5, RRX
		MOVS		R4, R4, RRX
		MOVS		R3, R3, RRX
		MOV		R10, R9
		SUBS		R11, R11, #1
		BNE		MULT
		STMIA	R2, {R3-R6}
		LDMED	R13!, {R0, R4-R12, PC}