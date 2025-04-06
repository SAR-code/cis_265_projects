/*
* SCRIPT: parameter_macros.c
* PURPOSE: Develop a C program that uses parameterized macros
* AUTHOR: D.M
* DATE: 06APR25
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#define CHECK(x,y,n) (((x) >= 0 && (x) <= ((n)-1)) && ((y) >= 0 && (y) <= ((n)-1)))
#define MEDIAN(x,y,z) (((x) - (y)) * ((z) - (x)) >= 0 ? x : ((y) - (x)) * ((z) - (y)) >= 0 ? y : z)

// Example of polynomial 3x^5 + 2x^4 - 5x^3 + x^2 - 7x + 6 
#define POLYNOMIAL(x) (3 * (x) * (x) * (x) * (x) * (x) + \
                        2 * (x) * (x) * (x) * (x) - \
                        5 * (x) * (x) * (x) + \
                        (x) * (x) - \
                        7 * (x) + 6)

// Function prototype for display_menu
void display_menu();



int main()
{
	// declare variables to test the macros
    int x = 2;
	int y = 4;
    int n = 6;
	int z = 8;

	// Test the macros
	printf("Testing macros with initial values:\n");
    printf("CHECK(%d,%d,%d) = %d\n", x, y, n, CHECK(x, y, n));
    printf("MEDIAN(%d,%d,%d) = %d\n", x, y, z, MEDIAN(x, y, z));
    printf("POLYNOMIAL(%d) = %d\n", x + 1, POLYNOMIAL(x + 1));

	// Call the display_menu function to interact with the user
	display_menu();


    return 0;
}

void display_menu()
{
	// declare variables to test macros
	int x, y, n, z;

    // declare a variable to capture the user's choice
    char userChoice;

	// declare a do while loop to display the menu until a valid choice is made

    do {

		// display the menu options to the user
        printf("\nSelect which function you would like to use:\n");
        printf("Press (C) to select CHECK\n");
        printf("Press (M) to select MEDIAN\n");
        printf("Press (P) to select POLYNOMIAL\n");
		printf("Press (Q) to quit the program\n");

        // prompt the user to enter a choice
        scanf(" %c", &userChoice);

        // converts ther user's response to uppercase
        userChoice = toupper(userChoice);

        // process the user's choice with switch case
		switch (userChoice) {
		case 'C': {
			// For CHECK macro, prompt the user for x, y, and n values
			printf("Enter values for x, y, and n: ");
			scanf("%d %d %d", &x, &y, &n);

			// Call the CHECK macro and print the result
			printf("CHECK(%d,%d,%d) = %d\n", x, y, n, CHECK(x, y, n));
			break;
		}
		case 'M': {
			// For MEDIAN macro, prompt the user for x, y, and z values
			printf("Enter values for x, y, and z: ");
			scanf("%d %d %d", &x, &y, &z);

			// Call the MEDIAN macro and print the result
			printf("MEDIAN(%d,%d,%d) = %d\n", x, y, z, MEDIAN(x, y, z));
			break;
		}
		case 'P': {
			// For POLYNOMIAL macro, prompt the user for x value
			printf("Enter a value for x: ");
			scanf("%d", &x);

			// Call the POLYNOMIAL macro and print the result
			printf("POLYNOMIAL(%d) = %d\n", x, POLYNOMIAL(x));
			break;
		}
		case 'Q':
			// Exit the program
			printf("Exiting the program.\n");
			break;
		default:
			// Handle invalid input
			printf("Invalid choice. Please try again.\n");
		}


    } while (userChoice != 'Q');
	

}
