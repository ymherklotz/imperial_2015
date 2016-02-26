				;		Test 0: simple diagnostic
INA0				DCD		0X30,0X2
INB0				DCD		0X7000,0X500
OUTAxB0			DCD		0X150000,0X1D000,0XA00,0X0
				
				;		Test 1: carries
INA1				DCD		0X7FFFFFFF,0X0
INB1				DCD		0X7FFFFFFF,0X0
OUTAxB1			DCD		0X1,0X3FFFFFFF,0X0,0X0
				
				;		Test 2: all zeros
INA2				DCD		0X0,0X0
INB2				DCD		0X0,0X0
OUTAxB2			DCD		0X0,0X0,0X0,0X0
				
				;		Test 3: both negative
INA3				DCD		0XFFFFFFFF,0XFFFFFFFF
INB3				DCD		0XFFFFFFFF,0XFFFFFFFF
OUTAxB3			DCD		0X1,0X0,0X0,0X0
				
				;		Test 4: A negative
INA4				DCD		0XFFFFFFFF,0XFFFFFFFF
INB4				DCD		0X1,0X0
OUTAxB4			DCD		0XFFFFFFFF,0XFFFFFFFF,0XFFFFFFFF,0XFFFFFFFF
				
				;		Test 5: B negative
INA5				DCD		0X1,0X0
INB5				DCD		0XFFFFFFFF,0XFFFFFFFF
OUTAxB5			DCD		0XFFFFFFFF,0XFFFFFFFF,0XFFFFFFFF,0XFFFFFFFF
				
				;		Test 6: Random bits
INA6				DCD		0X802A5B62,0XE705271E
INB6				DCD		0XB7353E54,0X2E4456B5
OUTAxB6			DCD		0X4951B828,0XAEC6916E,0XDF0A0C3D,0XFB7C41EF
				
				;		Test 7: Random bits
INA7				DCD		0X73F1A0B6,0X9B6FDBB8
INB7				DCD		0X3D1AA608,0XACA790C3
OUTAxB7			DCD		0XFE3F09B0,0X2829D69,0X913A81B,0X20BD7902
OUTVEC			FILL		4*4
REGVEC			FILL		8*4
STACKSAVE			FILL		4
IN_TEMP			FILL		4*4
				
				;
LAST_TEST			EQU		7
				MOV		R5, #0 ; test number
				;		Loop to test code with different data
TLOOP
				BL		DODATATEST
				ADD		R5, R5, #1
				CMP		R5, #LAST_TEST
				BLE		TLOOP
				;
				;
SUCCESS			MOV		R0, #123  ; 123 (0x7B) in R0 indicates successful completion of all tests
				END
				
				
DODATATEST		STMED	R13!, {R12,R14}
				LDR		R12, =INA0
				ADD		R12, R12, R5, LSL #5 ; get offset to correct data
				MOV		R0, R12 ; pointer to INA & INB
				LDR		R1, =IN_TEMP
				BL		COPY4W
				MOV		R0, R1      ; now R0 points to INA and INB copy
				ADD		R1, R0, #2*4 ; pointer to INB copy
				LDR		R2, =OUTVEC
				BL		SMUL_SHIELD
				ADD		R0, R12, #4*4 ; pointer to correct output
				LDR		R1, =OUTVEC ; pointer to actual 128 bit output
				MOV		R2, #4 ; length of vectors in words
				BL		VECTOREQ ; sets EQ cond if the two vectors are equal
				LDMEDEQ	R13!, {R12,PC} ; return
				;
DATA_ERROR
				MOV		R0, #-1
				;		we get here if we have found an error in the test
				;		R5 is the number of the test that failed
				;		R0 = -1 as error indication
				END
				
				
SMUL_SHIELD         ;         protect testbench registers ans stack from rogue SMUL behaviour
				;		check whether SMUL changes R4-R12
				STMED	R13!, {R4-R12, R14} ; save
				LDR		R3, =STACKSAVE
				STR		R13, [R3] ; save SP in case this gets corrupted
				LDR		R12, =INA6 ; the next 16 words of data are random
				AND		R3, R5, #1 ; extract LS bit of R5 which will change from test to test
				ADD		R12, R12, R3, LSL #2  ; add it onto R3 to make data in registers vary
				LDMIA	R12, {R4-R11}
				BL		SMUL64X64
				LDR		R0, =REGVEC
				STMIA	R0, {R4-R11}
				MOV		R1, R12
				MOV		R2, #8
				BL		VECTOREQ
				BNE		REG_ERROR
				LDR		R3, =STACKSAVE
				LDR		R3, [R3]
				MOV		R0, R13
				CMP		R3, R0
				LDMEDEQ	R13!, {R4-R12,R15} ; restore and return if no stack error
				
				
STACK_ERROR         ;        We get here if SMUL64X64 does not correctly restore the SP to its
				;		old value on exit (for example by using different push and pop register sets)
				MOV		R0, #-3
				LDMED	R13!, {R4-R12}
				END
				
				
				
				
REG_ERROR			;         we get here if the test code changes registers R4-R12, which is not allowed
				MOV		R0, #-2
				LDMED	R13!, {R4-R12}
				END
				
				
				;		return EQ if vectors of R2 words with LSWs at addresses R0 and R1 are equal
VECTOREQ		STMED	R13!, {R0,R1,R2,R4,R5,R14}
VLOOP			LDR		R5, [R0], #4
				LDR		R4, [R1], #4
				CMP		R5, R4
				LDMEDNE	R13!, {R0, R1,R2,R4,R5,PC} ; return with NE if the vectors do not match
				SUBS		R2, R2, #1
				BNE		VLOOP
				LDMED	R13!, {R0,R1,R2,R4,R5,PC} ; return with EQ if vectors match
				
				
				;		copy vector of 4 words from address R0 to address R1
COPY4W			STMED	R13!, {R4-R7,R14}
				LDMIA	R0, {R4-R7}
				STMIA	R1, {R4-R7}
				LDMED	R13!, {R4-R7, PC}
				
				
				;;		add your SMUL64X64 code from here onwards
