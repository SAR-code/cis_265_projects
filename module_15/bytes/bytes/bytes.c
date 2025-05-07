/*
* SCRIPT: bytes.c
* PURPOSE: Utilizes bitwise operations to write a program
*          that swaps the bytes from a hexidecimal number.
* AUTHOR: D.M
* DATE: 06MAY25
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



// Function prototype
unsigned short swap_bytes(unsigned short i);

int main()
{
	// Declare a variable to hold the hexadecimal number
	unsigned short i;

	// Prompt the user for input
	printf("Enter a hexadecimal number (up to four digits): ");
	scanf("%hx", &i);
	printf("Number with bytes swapped: %hx\n", swap_bytes(i));
	return 0;
}


/****************************************************
*                                                   *
* unsigned short swap_bytes(unsigned short integer) *
* Purpose: Swaps the bytes of a hexadecimal number. *
*                                                   *
****************************************************/
unsigned short swap_bytes(unsigned short i)
{
	// Swaps the bytes of the hexadecimal number
	unsigned short high_byte = i << 8;
	unsigned short low_byte = i >> 8;

	// returns the swapped bytes
	return high_byte | low_byte;
}

