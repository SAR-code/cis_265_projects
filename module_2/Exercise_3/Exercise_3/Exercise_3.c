/*
* SCRIPT: Exercise_3.c
* PURPOSE: This program breaks down the ISBN number entered by the user into different categories
* AUTHOR: D.M
* DATE: 26JAN25
* 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
    // declare variables to construct the full ISBN number

    int gsi_prefix;
    int group_id;
    int publisher_code;
    int item_num;
    int check_digit;

    // prompts the user to enter the ISBN
    printf("Enter ISBN: ");

    // user input ISBN with the dashes in between
    scanf("%d-%d-%d-%d-%d", &gsi_prefix, &group_id, &publisher_code, &item_num, &check_digit);

    // displays the break down message of the ISBN number
    printf("GSI prefix: %d\n", gsi_prefix);
    printf("Group Identifier: %d\n", group_id);
    printf("Publisher code: %d\n", publisher_code);
    printf("Item number: %d\n", item_num);
    printf("Check digit: %d\n", check_digit);


    return 0;
}


