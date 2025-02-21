/*
* SCRIPT: doubles.c
* PURPOSE: This program demonstrates the usage of pointer
*          arithmetic in the following doubles function
* AUTHOR: D.M
* DATE: 20FEB25
*
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// declare function prototype
double inner_product(const double* a, const double* b, int n);

int main()
{
    // declare test variables
    const double test_a[5] = { 1,2,3,4,5 };
    const double test_b[5] = { 1,2,3,4,5 };

    // display the output of the lists and function
    printf("Sum of Inner product: %f", inner_product(test_a, test_b, 5));

    return 0;


}

// function definition
double inner_product(const double* a, const double* b, int number) {

    // declare required variables
    double sum = 0;
    const double* pointer_a, * pointer_b;

    for (pointer_a = a, pointer_b = b; pointer_a < a + number && pointer_b < b + number; pointer_a++, pointer_b++) {

        // output pointers A and B
        printf("%f * %f = %f\n", *pointer_a, *pointer_b, *pointer_a * *pointer_b);

        sum += *pointer_a * *pointer_b;
    }

    return sum;


}

