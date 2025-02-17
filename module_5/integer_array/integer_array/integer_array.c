/*
* SCRIPT: integer_array.c
* PURPOSE: This program reads a 5 x 5 array of integers and then prints 
*          the row sums and the column sums
* AUTHOR: D.M
* DATE: 16FEB25
*
*/

#define _CRT_SECURE_NO_WARNINGS
#define ROWS 5
#define COLS 5

#include <stdio.h>


int main()
{
    // declare required variables
    int array[ROWS][COLS];
    int row_totals[ROWS] = { 0 };
    int column_totals[COLS] = { 0 };

    // declare a for loop to input numbers into each row
    for (int index = 0; index < ROWS; index++) {
        printf("Enter row %d: ", index + 1);
        scanf("%d%d%d%d%d", &array[index][0], &array[index][1], &array[index][2], &array[index][3], &array[index][4]);

    }

    // declare a for loop to iterate through the rows and columns
    for (int index = 0; index < ROWS; index++) {

        // nested for loop for the columns portion
        for (int jndex = 0; jndex < COLS; jndex++) {
            row_totals[index] += array[index][jndex];
            column_totals[jndex] += array[index][jndex];
        }
    }

    // display the row totals
    printf("\nRow totals:");
    for (int index = 0; index < ROWS; index++) {
        printf(" %d", row_totals[index]);
    }

    // display the column totals
    printf("\nColumn totals: ");
    for (int index = 0; index < COLS; index++) {
        printf(" %d", column_totals[index]);
    }

    return 0;
}


