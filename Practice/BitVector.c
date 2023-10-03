//Display the binary form of A using Shift and Bit Operators
#include <stdio.h>

//128 64 32 16 8 4 2 1
//0   1  0  0  0 0 0 1

void displayBitPatternLeft(unsigned char c){
	int numBits = sizeof(char)*8;
	
//	int i;
//	for(i = 0; i < 8; i++){
//		if((c << i) & (1 << 7)){
//			printf("1");
//			
//		} else {
//			printf("0");
//		}
//		printf(" -> 2^%d\n", bits*i);

	int i;
	for (i = 0; i < numBits; i++) {
        int bit = (c << i) & 1; // Extract the i-th bit
        printf("%d", bit); 	
    }

    printf("\n");
}


void main(){
	//display this into Shift and Bitwise Operators
	unsigned char c = 'A'; // A = 65 = 01000001

	
	//	Shift to the left
	displayBitPatternLeft(c);

	
//	printf("\nActual bit pattern of value: \n");
//	
//
//	printf("\n");
	
	//	Shift to the right
//	int x;
//	for(x = 7; x >= 0; x--){
//		if((c >> x) & 1 == 1){
//			printf("1");
//		} else {
//			printf("0");
//		}
//		printf(" -> %d\n", bits*i);
//	}
	
//	printf("\nActual bit pattern of value: \n");
}

//Study further the shifting to left and display its output every loop to understand
//long instead of char
