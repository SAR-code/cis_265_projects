/*
    SCRIPT: Exercise_4.c
    PURPOSE: The user inputs a cash amount with a decimal and 
             then displays the amount with 5% tax added.

    AUTHOR: D.M
    DATE: 18JAN25
*/


#include <stdio.h>
#define TAX .05f

int main()
{
    // declare variables for user input

    float userInput;
    float totalCalculation;

    // output mesage to the user to enter a dollar amount
    printf("Enter an amount: ");

    // stores the user input into the userInput variable
    scanf_s("%f", &userInput);

    // calculates the 5% tax then adds to total
    totalCalculation = (userInput * TAX) + userInput;

    // outputs total amount
    printf("With tax added: $%.2f", totalCalculation);

    return 0;
}


