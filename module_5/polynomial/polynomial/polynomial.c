/*
* SCRIPT: polynomial.c
* PURPOSE: The program computes the value of the polynomial given.
*          The user will enter a value for x.
* AUTHOR: D.M
* DATE: 16FEB25
*
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int compute_polynomial(int num);


int main()
{
    // declare required variables
    int number;

    // displays the question and prompts the user to enter a value for X
    printf("Here is the following polynomial:\n");
    printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6\n\n");
    printf("Enter the value of x: ");
    scanf("%d", &number);

    // displays the solution
    printf("The solution: %d\n", compute_polynomial(number));

    return 0;
}

// declare function to solve the polynomial
int compute_polynomial(int num) {

    // typing out the exponents within the polynomial
    int solution = (3 * num * num * num * num * num) + (2 * num * num * num * num) - (5 * num * num * num) - (num * num) + (7 * num) - 6;

    return solution;
}
