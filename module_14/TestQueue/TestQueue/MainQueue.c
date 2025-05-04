/*
* SCRIPT: MainQueue.c
* PURPOSE: Test the implementation of the Queue.h
*          and Queue.c files.
* AUTHOR: D.M
* DATE: 03MAY25
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Queue.h"


int main() {

	// Declare required variables
	int decision;
	int value;

	// Declare a while loop that contains the test menu
	while (1) {
		// Display the menu
		printf("\nQueue Test Menu:\n");
		printf("1. Insert item at end of queue\n");
		printf("2. Remove item from beginning of queue\n");
		printf("3. Return first item in queue\n");
		printf("4. Return last item in queue\n");
		printf("5. Check if queue is empty\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &decision);

		// Check the user's choice and call the appropriate function
		switch (decision) {
		case 1:

			// Prompt the user for a value to insert
			printf("Enter value to insert: ");
			scanf("%d", &value);
			insertEndQue(value);
			break;
		case 2:

			// Remove an item from the beginning of the queue
			removeBegQue();
			break;
		case 3:

			// Return the first item in the queue
			returnFirstItem();
			break;
		case 4:

			// Return the last item in the queue
			returnLastItem();
			break;
		case 5:

			// Check if the queue is empty
			if (isEmpty()) {
				printf("\nQueue is empty.\n");
			}
			else {
				printf("\nQueue is not empty.\n");
			}
			break;
		case 6:

			// Exit the program
			return 0;
		default:

			// Handle invalid input
			printf("\nInvalid choice. Please try again.\n");
		}
	}
}