#include <stdio.h>

void SMULT64X64(num0, num1, result0, result1) {

	previousBit = 0;
	result0 = num0;

	for(int i = 0; i < 64; i++) {
		currentBit = num0 & 1;

		if(currentBit == 0 && previousBit == 1) {
			result1 += num1;
		} else if(currentBit == 1 && previousBit == 0) {
			result1 -= num1;
		}

		result1 >> 1;
		result0 >rrc> 1;
		previousBit = currentBit;
	}
	printf("%d %d", result1, result0);
}

int main() {
	SMULT64X64(2, 3, 0, 0);
	return 0;
}
