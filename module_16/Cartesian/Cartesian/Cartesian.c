/*
* SCRIPT: Cartesian.c
* PURPOSE: This program complex number in Cartesian coordinates to polar form. 
           The user will enter a and b (the real and imaginary parts of the number); 
           the program will display the values of r and 0.
* AUTHOR: D.M
* DATE: 017MAY25
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// function prototypes
double handle_sqrt(double *real_num, double *imag_num);
double handle_atan(double *real_num, double *imag_num);

int main()
{
    // Declare required variables
    double real;
    double imaginary;
    double s_root;
    double theta;

    // Prompt the user to input the numbers
    printf("Enter real value of complex number: ");
    scanf("%lf", &real);
    printf("Enter imaginary value of complex number: ");
    scanf("%lf", &imaginary);

    s_root = handle_sqrt(&real, &imaginary);
    theta = handle_atan(&real, &imaginary);

    printf("s_root = %g\ntheta = %g rads\n", s_root, theta);

    
    return 0;
}

/*******************************************************
*                                                      *
* double handle_sqrt(double real_num, double imag_num) *
* Purpose: Handles the sqrt calculations               *
*                                                      *
********************************************************/

double handle_sqrt(double *real_num, double *imag_num) {

    // Squares the received arguments and returns the final output
    double squared_num = sqrt((*real_num * *real_num) + (*imag_num * *imag_num));

    return squared_num;

}

/*******************************************************
*                                                      *
* double handle_atan(double real_num, double imag_num) *
* Purpose: Handles the atan calculations               *
*                                                      *
********************************************************/

double handle_atan(double *real_num, double *imag_num) {

    // Calculates the received arguments and returns the final arc tangent
    double arc_tangent = atan( *imag_num / *real_num);

    return arc_tangent;

}