/*
* SCRIPT: programming_file.c
* PURPOSE: Develop a C program to perform several file I/O functions for the supplied “CIS265.txt” file
* AUTHOR: D.M
* DATE: 07MAR25
*
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COUNT_PER_LINE 1024
#define FILE_NAME "CIS265.txt"

// Function prototypes
void search_word_in_file(FILE* file);
void displayFileLines(FILE* file);
void appendingToFile(FILE* file);
void displayMenu();


int main()
{

	// invoke the display menu function to start the program
	displayMenu();

	
	return 0;
}


// declare a function to search for a word in a file

void search_word_in_file(FILE* file) {

	// declare required variables to execute the word search
	char word[MAX_COUNT_PER_LINE];
	char line[MAX_COUNT_PER_LINE];
	char editedLine[MAX_COUNT_PER_LINE * 2];
	int count = 0;

	// prompt the user to enter a word to search
	printf("Input the word you would like to search: ");
	scanf("%s", word);

	// Opens and reads the txt file
	FILE* tempFile = fopen(FILE_NAME, "r");
	if (tempFile == NULL) {
		printf("Error opening file.\n");
		return;
	}

	// Outputs message with the word in question
	printf("\nThis file occurrences of the word '%s' are:\n", word);

	// Loop through each line of the file
	while (fgets(line, MAX_COUNT_PER_LINE, tempFile)) {
		char* pointer = line;
		char* match;

		// resets the line that was edited
		editedLine[0] = '\0';
		int wordLen = strlen(word);


		// loops to search word on the current line
		while ((match = strstr(pointer, word)) != NULL) {

			// checks for complete matching words
			char start = (match == line) ? ' ' : *(match - 1);
			char end = *(match + strlen(word));

			// checks if the word is not part of another word
			if (!isalnum(start) && !isalnum(end)) {
				
				// highlights the word in question
				strncat(editedLine, pointer, match - pointer);
				strcat(editedLine, "[");
				strcat(editedLine, word);
				strcat(editedLine, "]");
				count++;
				pointer = match + wordLen;
			}
			else {
				strncat(editedLine, pointer, (match - pointer) + wordLen);
				pointer = match + wordLen;
			}
			
		}

		strcat(editedLine, pointer);

		printf("%s", editedLine);

	}

	// Outputs the total number of occurrences of the word
	printf("\nThe word '%s' was found %d times in the file.\n", word, count);
	fclose(tempFile);

}

// declare a function to count the number of lines in a file
void displayFileLines(FILE* file) {

	// declare required variables to execute the line count
	int numberOfLines = 0;
	int index = 0;

	char line[MAX_COUNT_PER_LINE];

	// prompt the user to enter the number of lines to display
	printf("Input the number of lines to display: ");
	scanf("%d", &numberOfLines);

	// Opens and reads the txt file
	FILE* tempFile = fopen(FILE_NAME, "r");
	if (tempFile == NULL) {
		printf("Error opening file.\n");
		return;
	}

	// Loop through each line of the file and display the lines
	for (index = 0; index < numberOfLines && fgets(line, MAX_COUNT_PER_LINE, tempFile) != NULL; index++) {
		printf("%s", line);
	}

	fclose(tempFile);
}

void appendingToFile(FILE* file) {

	// declare required variables to append to the file
	char newInformation[MAX_COUNT_PER_LINE];

	// opens and appends to txt file
	FILE* tempFile = fopen(FILE_NAME, "a");
	if (tempFile == NULL) {
		printf("Error opening file.\n");
		return;
	}

	// prompt the user to enter the information to append
	printf("Input the information to append: ");
	getchar();
	fgets(newInformation, MAX_COUNT_PER_LINE, stdin);

	// appends the information to the file
	fputs(newInformation, tempFile);

	printf("Information appended to the file successfully.\n");

	fclose(tempFile);
}


// declare a function to display the menu
void displayMenu() {

	// declare variable to capture the user's choice
	char userChoice;

	// open the text file for reading and writing
	FILE* file = fopen(FILE_NAME, "r+");
	if (file == NULL) {
		printf("Error opening file.\n");
		return 1;
	}

	// loop to display the menu until the user chooses to quit

	do {

		// displays the starting menu for the program and prompts the user to select an option

		printf("\nSelect from the options below on what you would like to do with this file:\n");
		printf("Press (S) to search for a word\n");
		printf("Press (L) to display specified number of text lines to the screen\n");
		printf("Press (A) to append new content to the file\n");
		printf("Press (Q) to quit\n");

		// prompt the user to enter a choice
		scanf(" %c", &userChoice);

		// converts the user's response to uppercase
		userChoice = toupper(userChoice);

		switch (userChoice) {
		case 'S':
			search_word_in_file(file);
			break;
		case 'L':
			displayFileLines(file);
			break;
		case 'A':
			appendingToFile(file);
			break;
		case 'Q':
			printf("Exiting the program.\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");

		}
		rewind(file);

	} while (userChoice != 'Q');

	// close the file
	fclose(file);

	
}

