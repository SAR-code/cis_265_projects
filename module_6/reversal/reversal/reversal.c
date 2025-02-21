/*
* SCRIPT: reversal.c
* PURPOSE: Write a program that reads a message then displays in reverse
*          using a pointer.
* AUTHOR: D.M
* DATE: 20FEB25
*
*/

#define _CRT_SECURE_NO_WARNINGS
#define CHARCOUNT 100
#define ENDFILE -1

#include <stdio.h>

// declare function prototypes
int receive_message(char a[], int num);
void print_message(char a[], int num);
void print_reverse_message(char a[], char* a_end);


int main()
{
    // declare required variables
    char message[CHARCOUNT];

    // storing the function into a variable
    int complete_message = receive_message(message, CHARCOUNT);

    // invoke the remaining functions
    print_message(message, complete_message);
    print_reverse_message(message, &message[complete_message - 1]);

    return 0;
}

// declare required functions

int receive_message(char a[], int num) {
    char characters;
    int index;

    // prompts the user to enter a message
    printf("Enter a message: ");
    for (index = 0; (characters = getchar()) != ENDFILE && characters != '\n'; index++) {
        a[index] = characters;
    }

    return index;
}


void print_message(char a[], int num) {
    char* point;

    printf("Message: ");

    // reads the received message
    for (point = a; point < a + num; point++) {
        printf("%c", *point);
    }

    printf("\n");
}

void print_reverse_message(char a[], char* a_end) {

    char* point = a_end;

    printf("Reversal with pointer is: ");
    
    // outputs the message in reverse
    while (point >= &a[0]) {
        printf("%c", *point--);
    }
    printf("\n");
}






