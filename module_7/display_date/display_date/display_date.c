/*
* SCRIPT: display_date.c
* PURPOSE: Write a program that accepts a date from the user in
*          the form MM/DD/YYYY and displays it in the form
*          Month Day, Year. For example, where Month is the name.
* AUTHOR: D.M
* DATE: 02MAR25
*
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// function prototype
void display_date(void);

int main()
{
    // invoke display_date function
	display_date();

	return 0;
}

void display_date(void) {

	// Declare an array to hold each Month
	const char* month_name[] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};

	// declare required variables
	int month = 0;
	int day = 0;
	int year = 0;

	// prompt user for date
	printf("Enter a date in the form MM/DD/YYYY: ");
	scanf(" %2d /%2d /%4d", &month, &day, &year);

	// display the revised date
	printf("You entered the date : %s %d, %d", *(month_name + (month - 1)), day, year);

}
