/*
* SCRIPT: Queue.h
* PURPOSE: Demonstrate the definition of a queue
*          utilizing a queue.h header file.
* AUTHOR: D.M
* DATE: 03MAY25
*
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_method* Queue;

// Defines inserting an item at the end of the queue
void insertEndQue(Item item);

// Defines removing an item from the beginning of the queue
Item removeBegQue();

// Defines returning the first item in the queue (without changing the queue)
Item returnFirstItem();

// Defines returning the last item in the queue (without changing the queue)
Item returnLastItem();

// Defines testing whether the queue is empty
bool isEmpty();

#endif
