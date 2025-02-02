/*
* SCRIPT: exercise4_octal.c
* PURPOSE: Displays integers entered by the user as an octal
* AUTHOR: D.M
* DATE: 01FEB25
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

    // declare required variables
    int user_input;
    int octal_conversion[5] = { 0 };
    int counter = 0;

    // prompts the user to enter a number between 0 and 32767
    printf("Enter a number between 0 and 32767: ");

    // user input with the numbers within the range
    scanf("%d", &user_input);

    // declare a while loop to iterate through the user input and convert it to octal
    while (user_input != 0) {

        octal_conversion[counter] = user_input % 8;
        user_input = user_input / 8;
        counter++;
    }

    // displays the octal number results, and places it on the same line
    printf("In octal, your number is: ");

    // ensures that every output contains 5 digits
    for (int index = 4; index >= 0; index--) {
        printf("%d", octal_conversion[index]);
    }
    
    return 0;
}


