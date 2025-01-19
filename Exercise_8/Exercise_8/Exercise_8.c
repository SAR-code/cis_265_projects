/*
    SCRIPT: Exercise_8.c
    PURPOSE: The program calculates the remaining balance on a loan
             after the first, second, and third monthly payments.

    AUTHOR: D.M
    DATE: 18JAN25
*/

#include <stdio.h>

int main()
{
    // declare variables required for the program

    float loanAmount;
    float interestRate;
    float monthlyPayment;
    float convertInterest;

    // declare payment variables
    float firstPaymentBalance;
    float secondPaymentBalance;
    float thirdPaymentBalance;


    // display the loan menu and prompt the user for loan input

    printf("Enter amount of loan: ");
    scanf_s("%f", &loanAmount);

    // display the interest menu and prompt the user for interest rate input

    printf("Enter interest rate: ");
    scanf_s("%f", &interestRate);

    // display the payment menu and prompt the user for monthly payment input

    printf("Enter monthly payment: ");
    scanf_s("%f", &monthlyPayment);

    // convert interest rate
    convertInterest = (interestRate / 100);

    // calculate the remaining balance after each payment

    // first payment results
    float baseBalance1 = (loanAmount - monthlyPayment);
    firstPaymentBalance = baseBalance1 + (loanAmount * (convertInterest / 12));

    // second payment results
    float baseBalance2 = (firstPaymentBalance - monthlyPayment);
    secondPaymentBalance = baseBalance2 + (firstPaymentBalance * (convertInterest / 12));

    // third payment results
    float baseBalance3 = (secondPaymentBalance - monthlyPayment);
    thirdPaymentBalance = baseBalance3 + (secondPaymentBalance * (convertInterest / 12));

    // display remaining balances after each monthly payment

    printf("\nBalance remaining after first payment: $%.2f\n", firstPaymentBalance);
    printf("Balance remaining after second payment: $%.2f\n", secondPaymentBalance);
    printf("Balance remaining after third payment: $%.2f\n", thirdPaymentBalance);


    return 0;
}


