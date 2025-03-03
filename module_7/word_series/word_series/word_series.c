/*
* SCRIPT: word_series.c
* PURPOSE: Write a program that finds the "smallest" and "largest" in
*          a series of words. This program will determine the order of the 
*         words based on the dictionary.
* AUTHOR: D.M
* DATE: 02MAR25
*
*/

#define _CRT_SECURE_NO_WARNINGS
#define LEN 20

#include <stdio.h>
#include <string.h>


// Function prototypes
void get_entered_word(void);
void load_words(void);
void word_comparison(void);

// global variables
char entered_word[LEN + 1];
char smallest_word[LEN + 1];
char largest_word[LEN + 1];


int main()
{
	//invvokes load_words function
	load_words();

	while (strlen(entered_word) != 4) {
		
		//invokes the word_comparison function
		word_comparison();
	}

	printf("\nSmallest word: %s\n", smallest_word);
	printf("Largest word: %s\n", largest_word);

    return 0;
}

// Function to get the word from the user
void get_entered_word(void) {

	// display the prompt for the user to enter a word
	printf("Enter word: ");
	scanf("%20s", entered_word);
}

// Function to load the words into the smallest and largest word variables
void load_words(void) {

	// invokes the get_entered_word function
	get_entered_word();

	// copies the entered word to the smallest word variable
	strcpy(smallest_word, entered_word);

	// copies the entered word to the largest word variable
	strcpy(largest_word, entered_word);

}

void word_comparison(void) {

	// invokes the get entered word function
	get_entered_word();

	// compares the entered word with the smallest word or the largest word
	if (strcmp(entered_word, smallest_word) < 0) {
		strcpy(smallest_word, entered_word);
	}
	else if (strcmp(entered_word, largest_word) > 0) {
		strcpy(largest_word, entered_word);
	}
}
	

