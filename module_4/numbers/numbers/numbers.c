/*
* SCRIPT: numbers.c
* PURPOSE: Finds the largest number in a series of numbers
*          entered by the user.
* AUTHOR: D.M
* DATE: 06FEB25
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    // declare required variables
    float numbers;
    float max_number;
    

    // prompt the user to enter a number
    printf("Enter a number and we will determine which one is the largest (enter 0 or a negative number to stop)\n");
    printf("Enter a number: ");

    // captures the number entered in by the user
    scanf("%f", &numbers);

    // assume the initial numbers are entered before comparing them with other numbers
    max_number = numbers;

    while (numbers > 0) {

        // continues the prompt until the dummy flag is entered
        printf("Enter a number: ");
        scanf("%f", &numbers);

        // compares each number to the previous number then reassigns max if a larger
        // number is found
        if (numbers > max_number) {
            max_number = numbers;
        }

    }

    // displays message once the largest number is detected
    printf("\nThe largest number entered was %.2f\n", max_number);

    return 0;
}


