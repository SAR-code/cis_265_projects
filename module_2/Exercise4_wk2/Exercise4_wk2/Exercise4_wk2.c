/*
* SCRIPT: Exercise4_wk2.c
* PURPOSE: This program translates an alphabet phone number into a numeric form
* AUTHOR: D.M
* DATE: 26JAN25
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
    // declare variables for user input
    char phone_num;

    // declare variable to exit while loop
    char exit = 'z';

    // prompt user to exit the program when complete
    printf("Press %c to exit", exit);

    // prompt user to enter phone number
    printf("\nEnter phone number: ");


    // declare a while loop to receive and translate user input

    while ((phone_num = getchar()) != exit) {
        if (phone_num == 'A' || phone_num == 'B' || phone_num == 'C') {
            printf("2");
        }
        else if (phone_num == 'D' || phone_num == 'E' || phone_num == 'F') {
            printf("3");
        }
        else if (phone_num == 'G' || phone_num == 'H' || phone_num == 'I') {
            printf("4");
        }
        else if (phone_num == 'J' || phone_num == 'K' || phone_num == 'L') {
            printf("5");
        }
        else if (phone_num == 'M' || phone_num == 'N' || phone_num == 'O') {
            printf("6");
        }
        else if (phone_num == 'P' || phone_num == 'R' || phone_num == 'S') {
            printf("7");
        }
        else if (phone_num == 'T' || phone_num == 'U' || phone_num == 'V') {
            printf("8");
        }
        else if (phone_num == 'W' || phone_num == 'X' || phone_num == 'Y') {
            printf("9");
        }
        else {
            //displays output and promptd the user to exit the loop
            printf("%c", phone_num);
        };


    };


 
    return 0;
}


