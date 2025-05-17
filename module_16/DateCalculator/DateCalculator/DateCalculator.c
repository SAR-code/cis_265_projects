/*
* SCRIPT: DateCalculator.c
* PURPOSE: This program prompts the user to enter two dates, 
           then prints the difference between them, measure in days.
* AUTHOR: D.M
* DATE: 17MAY25
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

struct tm timeOne, timeTwo;

// Function prototypes
void handle_input();

int main()
{

    // Invokes the function handle_input
    handle_input();

    return 0;
}


void handle_input(){

    // Declare struct members
    timeOne.tm_hour = 0;
    timeOne.tm_min = 0;
    timeOne.tm_sec = 0;
    timeTwo = timeOne;

    // Prompt the user to input the two dates
    printf("First Date: Enter month (1-12): ");
    scanf("%d", &timeOne.tm_mon);
    timeOne.tm_mon--;

    printf("First Date: Enter day (1-31): ");
    scanf("%d", &timeOne.tm_mday);

    printf("First Date: Enter year (Lowest year is 1900): ");
    scanf("%d", &timeOne.tm_year);
    timeOne.tm_year -= 1900;

    // Prompt the user to input Second Date
    printf("Second Date: Enter month (1-12): ");
    scanf("%d", &timeTwo.tm_mon);
    timeTwo.tm_mon--;

    printf("Second Date:: Enter day (1-31): ");
    scanf("%d", &timeTwo.tm_mday);

    printf("Second Date:: Enter year (1900+): ");
    scanf("%d", &timeTwo.tm_year);
    timeTwo.tm_year -= 1900;

    // Displays the calculated dates measured in days
    printf("Days between dates: %d\n",
        (int)(difftime(mktime(&timeTwo), mktime(&timeOne)) / 60 / 60 / 24));
    
}




