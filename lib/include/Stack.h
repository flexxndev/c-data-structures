#ifndef C_DATA_STRUCTURES_STACK_H
#define C_DATA_STRUCTURES_STACK_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define INITIAL_CAPACITY 16

typedef int (*compare_func)(const void *e1, const void *e2);
typedef void (*print_func)(const void *data);

typedef struct {
    void **data;
    int size;
    int capacity;
    compare_func compare;
    print_func print;
} Stack;

/*
    Creates a stack with an initial capacity
    of 16 spaces for elements that can be added. 
    If there is not enough space, the stack 
    resizes with more space
*/
void createStack(Stack *s, compare_func compare, print_func print);

/*
    Creates a stack with the initial capacity
    passed as a parameter for elements that
    can be added. If there is not enough
    space, the stack resizes with more space
*/
void createStackWithCapacity(Stack *s, int capacity, compare_func compare, print_func print);

/*
    Delete the stack and release memory
    reserved for the elements of the stack

    Complexity: O(1)
*/
void deleteStack(Stack *s);

/*
    Remove all the elements of the stack
    and release memory reserved for these
    elements. The stack will be empty after
    calling this function. 
    
    Complexity: O(1)
*/
void clearStack(Stack *s);

/*
    Return the number of elements in the stack
*/
int sizeStack(Stack s);

/*
    Return true if the stack is empty or
    false if not
*/
bool isEmptyStack(Stack s);

/*
    Print the elements of the stack
    using the print function passed
    as a parameter. If the stack is
    empty, print "Empty Stack."
*/
void printStack(Stack s);

/*
    Add the element passed as a parameter
    at the top of the stack. If there is
    not enough space, the stack resizes
    with more space. 
    
    Complexity: O(1)
*/
void push(Stack *s, void *e);

/*
    Add the elements of the array passed as
    a parameter at the top of the stack. The
    first element of the array is the lower
    element of the stack and the last element
    of the array is the higher element of the
    stack. If there is not enough space, the
    stack resizes with more space. 
    
    Complexity: O(n)
*/
void pushArray(Stack *s, void **array, int n);

/*
    Add the elements of the stack origin
    at the top of the stack destination. 

    Complexity: O(n)
*/
void pushStack(Stack *destination, Stack origin);

/*
    Remove the element at the top of the stack
    and return it. If there is no elements,
    return null. 
    
    Complexity: O(1)
*/
void* pop(Stack *s);

/*
    Remove n elements at the top of the stack and 
    return an array with these elements. The first 
    element of the array is the higher element of 
    the stack and the last element is the lower 
    element. If there is no elements, return null. 
    If n is greater than the size of the stack, 
    return all the elements of the stack.

    Complexity: O(n)
*/
void** popNElements(Stack *s, int n);

/*
    Return the element at the index passed as
    a parameter. The first element of the stack
    is the element at index 0. If there is no
    elements or the index is out of bounds, 
    return null. 
    
    Complexity: O(1)
*/
void* getStack(Stack s, int index);

/*
    Return the lower element of the stack
    without removing it. If there is no
    elements, return null.

    Complexity: O(1)
*/
void* getFirstStack(Stack s);

/*
    Return the higher (peek) element of
    the stack without removing it. If
    there is no elements, return null.

    Complexity: O(1)
*/
void* getLastStack(Stack s);

/*
    Return the higher (peek) element of
    the stack without removing it. If
    there is no elements, return null.

    Complexity: O(1)
*/
void* peek(Stack s);

/*
    Find the element passed as a parameter
    in the stack and return its index. If
    the element is not found or the stack
    is empty, return -1. 
    
    Complexity: O(n)
*/
int searchStack(Stack s, void *e);

/*
    Return true if the element passed as a
    parameter is in the stack or false
    if not. 
    
    Complexity: O(n)
*/
bool containsStack(Stack s, void *e);

/*
    Return an array with all the elements
    of the stack. The first element of
    the array is the lower element of the
    stack and the last element of the array
    is the higher element of the stack. If
    the stack is empty, return an array of
    size 0. 
    
    Complexity: O(n)
*/
void** stackToArray(Stack s);

/* 
    Return true if the stack s1 is
    equal to the stack s2 or false
    if not. Two stacks are equal if
    they have the same size, the same
    compare function and their elements 
    are equal (in the same order).
*/
bool equalsStack(Stack s1, Stack s2);

#endif //C_DATA_STRUCTURES_STACK_H