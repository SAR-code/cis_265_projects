/*
* SCRIPT: SegmentDisplay.c
* PURPOSE: This program prompts the user for a number then
*          displays the number on a simulated 7-segment display.
* AUTHOR: D.M
* DATE: 13APR25
*
*/

#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

// define display dimensions

#define DIGIT_H 3
#define DIGIT_W 3
#define DIGIT_SPACE 1

#define MAX_DIGIT_SPACE (MAX_DIGITS * (DIGIT_W + DIGIT_SPACE) - DIGIT_SPACE)
#define MAX_SECTIONS 7


// function prototypes
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);


/******************************************************
*                                                     *
* contains sections of each digit 0-9                 *
*                                                     *
*    0                                                *
*   ---                                               *
* 5|   |1                                             *
*  |_6_|                                              *
* 4|   |2                                             *
*  |___|                                              *
*    3                                                *
*******************************************************/

const int digit_sections[10][7] = {
		  {1, 1, 1, 1, 1, 1, 0}, // 0
		  {0, 1, 1, 0, 0, 0, 0}, // 1
		  {1, 1, 0, 1, 1, 0, 1}, // 2
		  {1, 1, 1, 1, 0, 0, 1}, // 3
		  {0, 1, 1, 0, 0, 1, 1}, // 4
		  {1, 0, 1, 1, 0, 1, 1}, // 5
		  {1, 0, 1, 1, 1, 1, 1}, // 6
		  {1, 1, 1, 0, 0, 0, 0}, // 7
		  {1, 1, 1, 1, 1, 1, 1}, // 8
		  {1, 1, 1, 1, 0, 1, 1}  // 9
};

/********************************************************************
* creates the 3x3 grid for the positioning of the 7 section display *
*                                                                   *
*********************************************************************/

const int sectional_grid[MAX_SECTIONS][2] = {
	{0, 1}, // section 0
	{1, 2}, // section 1
	{2, 2}, // section 2
	{2, 1}, // section 3
	{2, 0}, // section 4
	{1, 0}, // section 5
	{1, 1}  // section 6
};

char digits_array[DIGIT_H][MAX_DIGIT_SPACE];


int main()
{
	// declare local variables
	char characters;
	int position = 0;

	// invoke clear_digits_array function
	clear_digits_array();

	// prompt user for input
	printf("Enter a number (0-9): ");

	// read characters until newline or max space
	while ((characters = getchar()) != '\n' && position < MAX_DIGIT_SPACE) {

		// check if character is a digit
		if (isdigit(characters)) {
			process_digit(characters - '0', position);
			position += DIGIT_W + DIGIT_SPACE;
		}
	}

	// output the digits array
	print_digits_array();

    return 0;
}

/****************************************************
* 		                                    *
* void clear_digits_array(void)			    *
* Purpose: Clears the digits array to spaces.	    *
* 						    *
*****************************************************/

void clear_digits_array(void)
{
	int rows;
	int cols;

	for (rows = 0; rows < DIGIT_H; rows++) {
		for (cols = 0; cols < MAX_DIGIT_SPACE; cols++) {
			digits_array[rows][cols] = ' ';
		}
	}
	
}


/****************************************************
* 						    *
* void process_digit(int digit, int position)	    *
* Purpose: Processes the digit and updates the	    *
* digits array to display the digit.	            *
* 						    *
* ***************************************************/

void process_digit(int digit, int position)
{
	int section;
	int row;
	int col;

	for (section = 0; section < MAX_SECTIONS; section++) {

		if (digit_sections[digit][section]) {
			row = sectional_grid[section][0];
			col = sectional_grid[section][1] + position;
			digits_array[row][col] = section % 3 == 0 ? '_' : '|';

		}
	}
}


/****************************************************
* 						    *
* void print_digits_array(void)			    *
* Purpose: Prints the digits array to the console.  *
* 						    *
*****************************************************/

void print_digits_array(void)
{
	int rows;
	int cols;
	for (rows = 0; rows < DIGIT_H; rows++) {
		for (cols = 0; cols < MAX_DIGIT_SPACE; cols++) {
			printf("%c", digits_array[rows][cols]);
		}
		printf("\n");
	}
}


