/*
* SCRIPT: calendar.c
* PURPOSE: This program prints a one month calendar. The user sets
*          the calendar but entering the count of days and day of the week.
* AUTHOR: D.M
* DATE: 08FEB25
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    // declare required variables

    int num_days_input;
    int days_of_week;

    //prompt the user to enter the amount of days
    printf("Enter number of days in month: ");
    scanf("%d", &num_days_input);

    // promtpt the user to enter the day of the week
    printf("Enter starting day of the week (1-Sun, 7=Sat): ");
    scanf("%d", &days_of_week);

    days_of_week--;

    // for loop to set up month formatting
    for (int index = 0; index < days_of_week; index++) {
        printf("   ");
    }

    // for loop to match the number of days to the starting week day
    for (int jdex = 1; jdex <= num_days_input; jdex++) {
        printf("%2d", jdex);

        if ((jdex + days_of_week) % 7 == 0) {
            printf("\n");
        }
        else {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}


