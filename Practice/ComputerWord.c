// Display the binary form of A using Shift and Bit Operators
#include <stdio.h>

// 128 64 32 16 8 4 2 1
// 0   1  0  0  0 0 0 1

void displayBitPatternRight(unsigned char c)
{
	int numBits = sizeof(char) * 8;
	printf("Number of bits in a char: %d\n", numBits);

	for (int i = numBits - 1; i >= 0; i--)
	{
		int bit = (c >> i) & 1; // Extract the i-th bit by shifting right
		printf("%d", bit);
	}

	printf("\n");
}

void displayBitPatternLeft(unsigned char c)
{
	int numBits = sizeof(char) * 8;
	printf("Number of bits in a char: %d\n", numBits);

	for (int i = 0; i < numBits; i++)
	{
		int bit = (c << i) & (1 << (numBits - 1)); // Extract the i-th bit by shifting left
		printf("%d", bit != 0 ? 1 : 0);
	}

	printf("\n");
}

void main()
{
	// display this into Shift and Bitwise Operators
	unsigned char c = 'A'; // A = 65 = 01000001

	//	Display the binary representation using a function
	displayBitPatternLeft(c);
	printf("\n");
	displayBitPatternRight(c);
}

// Study further the shifting to left and display its output every loop to understand
// long instead of char
