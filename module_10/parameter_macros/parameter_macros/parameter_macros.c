/*
* SCRIPT: parameter_macros.c
* PURPOSE: Develop a C program that uses parameterized macros
* AUTHOR: D.M
* DATE: 06APR25
*
*/

#include <stdio.h>


#define CHECK(x,y,n) (((x) >= 0 && (x) <= ((n)-1)) && ((y) >= 0 && (y) <= ((n)-1)))
#define MEDIAN(x,y,z) (((x) - (y)) * ((z) - (x)) >= 0 ? x : ((y) - (x)) * ((z) - (y)) >= 0 ? y : z)

// Example of polynomial 3x^5 + 2x^4 - 5x^3 + x^2 - 7x + 6 
#define POLYNOMIAL(x) (3 * (x) * (x) * (x) * (x) * (x) + \
                        2 * (x) * (x) * (x) * (x) - \
                        5 * (x) * (x) * (x) + \
                        (x) * (x) - \
                        7 * (x) + 6)

int main()
{
	// declare variables to test the macros
    int x = 2;
	int y = 4;
    int n = 6;

	// Test the macros
    printf("CHECK(%d,%d,%d) = %d\n", x, y, n, CHECK(x, y, n));
    printf("MEDIAN(%d,%d,%d) = %d\n", x, y, n, MEDIAN(x, y, n));
    printf("POLYNOMIAL(%d) = %d\n", x + 1, POLYNOMIAL(x + 1));

    return 0;
}
