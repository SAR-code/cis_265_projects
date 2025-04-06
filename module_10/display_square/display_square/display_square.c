/*
* SCRIPT: display.c
* PURPOSE: Develop a C program that uses a macro DISP(f,x)
*          that expands into a call of printf to display the
*          value of function f when called with x.
* AUTHOR: D.M
* DATE: 06APR25
*
*/

#include <stdio.h>
#include <math.h>

// Define the macro DISP
#define DISP(f,x) printf("%s(%g) = %g\n", (#f), (x), (f(x)))

// Define the macro DISP2 for functions with two arguments
#define DISP2(f,x,y) printf("%s(%g, %g) = %g\n", (#f), (x), (y), (f(x,y)))


int main()
{
    // Use the macro DISP to display the square entered
    DISP(sqrt, 3.0);

    // Use the macro DISP2 to display the result of a function with two arguments
    DISP2(pow, 3.0, 2.0);

    return 0;
}
