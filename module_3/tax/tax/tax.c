/*
* SCRIPT: tax.c
* PURPOSE: This program receives the user's taxable income then returns
*          the amount of tax due
* AUTHOR: D.M
* DATE: 01FEB25
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
    // declare required variables
    int user_income;
    float tax_owed;
    float taxed_rate;

    // prompt the user to enter their taxable income
    printf("Enter your taxable income: ");

    // retrieves the user's input
    scanf("%d", &user_income);


    // conditional statements to determine which tax bracket the user pays taxes

    if (user_income <= 750) {

        // calculates the amount of tax at the 1% level
        taxed_rate = (user_income * .01);
        tax_owed = taxed_rate;

        // displays taxes due based off the taxed rate
        printf("Taxes due: $%.2f", tax_owed);
    }
    else if (user_income <= 2250) {

        // stores the taxed rate based off income
        taxed_rate =  7.50;

        // calculates taxes sum based off tax rate and 2% of user income
        tax_owed = taxed_rate + (user_income * .02);

        // displays taxes due based of the taxed rate
        printf("Taxes due: $%.2f", tax_owed);
    }
    else if (user_income <= 3750) {

        // stores the taxed rate based off income
        taxed_rate = 37.50;

        // calculate taxes sum based off tax rate and 3% of user income
        tax_owed = taxed_rate + (user_income * .03);
        
        // displays taxes due based of the taxed rate
        printf("Taxes due: $%.2f", tax_owed);
    }
    else if (user_income <= 5250) {

        // stores the taxed rate based off income
        taxed_rate = 82.50;

        // calculate taxes sum based off tax rate and 4% of user income
        tax_owed = taxed_rate + (user_income * .04);

        // displays taxes due based of the taxed rate
        printf("Taxes due: $%.2f", tax_owed);
    }
    else if (user_income <= 7000) {

        // stores the taxed rate based off income
        taxed_rate = 142.50;

        // calculate taxes sum based off tax rate and 5% of user income
        tax_owed = taxed_rate + (user_income * .05);

        // displays taxes due based of the taxed rate
        printf("Taxes due: $%.2f", tax_owed);
    }
    else if (user_income > 7000) {

        // stores the taxed rate based off income
        taxed_rate = 230;

        // calculate taxes sum based off tax rate and 6% of user income
        tax_owed = taxed_rate + (user_income * .06);

        // displays taxes due based of the taxed rate
        printf("Taxes due: $%.2f", tax_owed);
    }
    
    
   
    
    
        
    

    return 0;
}


