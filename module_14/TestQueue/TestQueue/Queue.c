/*
* SCRIPT: Queue.c
* PURPOSE: Demonstrate the implementation of a queue
*          utilizing a queue.h header file.
* AUTHOR: D.M
* DATE: 03MAY25
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// Define the queue structure
struct queue_structure
{
	Item items[100]; // Array to hold the items
	int front;      // Index of the front item
	int rear;       // Index of the rear item
	int size;       // Current size of the queue

};

// Create a queue instance
static struct queue_structure queue = {
.front = 0,
.rear = -1,
.size = 0
};


/****************************************************
* 		                                            *
* void insertEndQue(Item item)		                *
* Purpose: Inserts item at the end of the queue     *
* 						                            *
*****************************************************/
void insertEndQue(Item item)
{
	// Checks to see if the queue is full
	if (queue.size == 100)
	{
		printf("\nQueue is full. Cannot insert %d\n", item);
		return;
	}

	// Adds the item to the rear of the queue
	queue.rear = (queue.rear + 1) % 100;
	queue.items[queue.rear] = item;
	queue.size++;
	printf("\nInserted %d into the queue\n", item);
}


/********************************************************
* 		                                                *
* Item removeBegQue()			                        *
* Purpose: Removes item from the beginning of the queue *
*                                                       *
********************************************************/
Item removeBegQue()
{
	// Checks to see if the queue is empty
	if (isEmpty())
	{
		printf("Queue is empty");
		return -1;
	}

	// Removes the item from the front of the queue
	Item item = queue.items[queue.front];
	queue.front = (queue.front + 1) % 100;
	queue.size--;
	printf("\nRemoved %d from the queue\n", item);
	return item;
}


/********************************************************
* 		                                                *
* Item returnFirstItem()			                    *
* Purpose: Returns the first item in the queue          *
*                                                       *
********************************************************/
Item returnFirstItem()
{
	// Checks to see if the queue is empty
	if (isEmpty())
	{
		printf("Queue is empty");
		return -1;
	}

	// Returns the first item in the queue
	Item item = queue.items[queue.front];
	printf("\nFirst item in the queue is %d\n", item);
	return item;
}


/********************************************************
* 		                                                *
* Item returnLastItem()			                        *
* Purpose: Returns the last item in the queue           *
* 												        *
* ******************************************************/
Item returnLastItem()
{
	// Checks to see if the queue is empty
	if (isEmpty())
	{
		printf("Queue is empty");
		return -1;
	}

	// Returns the last item in the queue
	Item item = queue.items[queue.rear];
	printf("\nLast item in the queue is %d\n", item);
	return item;
}


/********************************************************
* 		                                                *
* bool isEmpty()			                            *
* Purpose: Tests whether the queue is empty             *
* 												        *
* ******************************************************/
bool isEmpty()
{
	return queue.size == 0;
}


