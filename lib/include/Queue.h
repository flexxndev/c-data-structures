#ifndef C_DATA_STRUCTURES_QUEUE_H
#define C_DATA_STRUCTURES_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef int (*compare_func)(const void *e1, const void *e2);
typedef void (*print_func)(const void *data);

typedef struct Node {
    void *data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    int size;
    Node *first;
    Node *last;
    compare_func compare;
    print_func print;
} Queue;

/*
    Creates a dynamic Queue
*/
void createQueue(Queue *q, compare_func compare, print_func print);

/*
    Delete the Queue and release memory
    reserved for the elements of the Queue.

    Complexity: O(n)
*/
void deleteQueue(Queue *q);

/*
    Remove all the elements of the Queue
    and release memory reserved for these
    elements. The Queue will be empty after
    calling this function.

    Complexity: O(n)
*/
void clearQueue(Queue *q);

/*
    Return the number of elements in the Queue
*/
int sizeQueue(Queue q);

/*
    Return true if the Queue is empty or
    false if not
*/
bool isEmptyQueue(Queue q);

/*
    Print the elements of the Queue
    using the print function passed
    as a parameter. If the Queue is
    empty, print "Empty Queue."
*/
void printQueue(Queue q);

/*
    Add the element passed as a parameter
    at the back of the Queue.

    Complexity: O(1)
*/
void enqueue(Queue *q, void *e);

/*
    Add the elements of the array passed as
    a parameter at the back of the Queue. The
    last element of the array is the last one
    element of the Queue.

    Complexity: O(n)
*/
void enqueueArray(Queue *q, void **array, int n);

/*
    Add the elements of the Queue origin
    at the back of the Queue destination.

    Complexity: O(n)
*/
void enqueueQueue(Queue *destination, Queue origin);

/*
    Remove the first element of the Queue
    and return it. If there is no elements,
    return null.

    Complexity: O(1)
*/
void* dequeue(Queue *q);

/*
    Remove n elements at the front of the Queue and 
    return an array with these elements. The first 
    element of the array is the first element of 
    the Queue. If there is no elements, return null. 
    If n is greater than the size of the Queue, 
    return all the elements of the Queue.

    Complexity: O(n)
*/
void** dequeueNElements(Queue *q, int n);

/*
    Return the element at the index passed as
    a parameter. The first element of the Queue
    is the element at index 0. If there is no
    elements or the index is greater than the
    size of the Queue, return null.

    Complexity: O(n)
*/
void* getQueue(Queue q, int index);

/*
    Return the first element of the Queue
    without removing it. If there is no
    elements, return null.

    Complexity: O(1)
*/
void* getFirstQueue(Queue q);

/*
    Return the last element of the Queue
    without removing it. If there is no
    elements, return null.

    Complexity: O(1)
*/
void* getLastQueue(Queue q);

/*
    Return the first element of the Queue
    without removing it. If there is no
    elements, return null.

    Complexity: O(1)
*/
void* front(Queue q);

/*
    Return the last element of the Queue
    without removing it. If there is no
    elements, return null.

    Complexity: O(1)
*/
void* back(Queue q);

/*
    Find the element passed as a parameter
    in the Queue and return its index. If
    the element is not found or the Queue
    is empty, return -1.

    Complexity: O(n)
*/
int searchQueue(Queue q, void *e);

/*
    Return true if the element passed as a
    parameter is in the Queue or false
    if not.

    Complexity: O(n)
*/
bool containsQueue(Queue q, void *e);

/*
    Return an array with all the elements
    of the Queue. The first element of
    the array is the first element of the
    Queue and the last element of the array
    is the last element of the Queue.

    Complexity: O(n)
*/
void** queueToArray(Queue q);

/* 
    Return true if the Queue q1 is
    equal to the Queue q2 or false
    if not. Two Queues are equal if
    they have the same size, the same
    compare function and their
    elements are equal (in the same
    order)
*/
bool equalsQueue(Queue q1, Queue q2);

#endif //C_DATA_STRUCTURES_QUEUE_H