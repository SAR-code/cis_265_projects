/*
* SCRIPT: word_sort.c
* PURPOSE: Develop a C program that sorts a series of words entered 
*          by the user.
* AUTHOR: D.M
* DATE: 20MAR25
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

// function prototypes
int word_comparison(const void* first_word, const void* second_word);

int main()
{
    // declare required variables
    char** words;
    char* single_word;
    int index = 0;
    int word_count = 0;

    // allocates space for the char in the words array
    if ((words = malloc(sizeof(char*))) == NULL) {
        printf("Malloc Failed.\n");
        exit(EXIT_FAILURE);
    }

    for (index = 0, word_count = 0; ;index++, word_count++) {
        if ((single_word = malloc(MAX_LEN + 1)) == NULL) {
            printf("Malloc failed.\n");
            exit(EXIT_FAILURE);
        }

        // display the message to prompt the user to enter a word
        printf("Enter a word: ");
        fgets(single_word, MAX_LEN + 1, stdin);
        single_word[strlen(single_word) - 1] = '\0';

        if (single_word[0] == '\0')
            break;

        *(words + index) = single_word;

        words = realloc(words, sizeof(char*) * (word_count + 2));
    }

    // invoke the qsort function with the words in question
    qsort(words, word_count, sizeof(char*), word_comparison);

    // displays and organizes the words in question.
    printf("\nWords sorted\n");
    for (index = 0; index < word_count; index++) {
        printf("%s\n", *(words + index));
    }

    return 0;
}

// declare function to compare the entered words
int word_comparison(const void* first_word, const void* second_word)
{
    return strcmp(*(char**)first_word, *(char**)second_word);
}

