#include "Stack.h"

static void resizeStack(Stack *s) {
    int newCapacity = s->capacity * 2;
    void **data = realloc(s->data, newCapacity * sizeof(void*));

    if (!data) {
        fprintf(stderr, "Error: No memory available\n");
        exit(1);
    }
    s->data = data;
    s->capacity = newCapacity;
}

void createStack(Stack *s, compare_func compare, print_func print) {
    createStackWithCapacity(s, INITIAL_CAPACITY, compare, print);
}

void createStackWithCapacity(Stack *s, int capacity, compare_func compare, print_func print) {
    s->data = (void **) malloc (capacity * sizeof(void*));
    if (!s->data) {
        fprintf(stderr, "Error: No memory available\n");
        exit(1);
    }
    s->size = 0;
    s->capacity = capacity;
    s->compare = compare;
    s->print = print;
}

void deleteStack(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
}

void clearStack(Stack *s) {
    compare_func compare = s->compare;
    print_func print = s->print;

    deleteStack(s);
    createStackWithCapacity(s, INITIAL_CAPACITY, compare, print);
}

int sizeStack(Stack s) {
    return s.size;
}

bool isEmptyStack(Stack s) {
    return s.size == 0;
}

void printStack(Stack s) {
    int cont;

    if (s.size == 0) {
        printf("Empty Stack.\n");
    } else {
        printf("Stack:\n");
        for (cont = 0; cont < s.size; cont++) {
            printf("Element %d: ", cont + 1);
            s.print(s.data[cont]);
        }
    }
}

void push(Stack *s, void *e) {
    if (s->capacity <= s->size) {
        resizeStack(s);
    }
    s->data[s->size] = e;
    (s->size)++;
}

void pushArray(Stack *s, void **array, int n) {
    int cont;

    while (s->capacity <= s->size + n) {
        resizeStack(s);
    }
    for (cont = 0; cont < n; cont++) {
        push(s, array[cont]);
    }
}

void pushStack(Stack *destination, Stack origin) {
    int cont;

    while (destination->capacity <= destination->size + origin.size) {
        resizeStack(destination);
    }
    for (cont = 0; cont < origin.size; cont++) {
        push(destination, origin.data[cont]);
    }
}

void* pop(Stack *s) {
    if (s->size == 0) {
        return NULL;
    }
    (s->size)--;
    return s->data[s->size];
}

void** popNElements(Stack *s, int n) {
    int cont;
    if (s->size == 0) {
        return NULL;
    } else if (s->size - n < 0) {
        n = s->size;
    }
    void **array = (void**) malloc (n * sizeof(void*));

    for (cont = 0; cont < n; cont++) {
        array[cont] = pop(s);
    }
    return array;
}

void* getStack(Stack s, int index) {
    if (s.size == 0 || index >= s.size || index < 0) {
        return NULL;
    }
    return s.data[index];
}

void* getFirstStack(Stack s) {
    if (s.size == 0) {
        return NULL;
    }
    return s.data[0];
}

void* getLastStack(Stack s) {
    if (s.size == 0) {
        return NULL;
    }
    return s.data[s.size - 1];
}

void* peek(Stack s) {
    return getLastStack(s);
}

int searchStack(Stack s, void *e) {
    int cont;

    for (cont = 0; cont < s.size; cont++) {
        if (s.compare(s.data[cont], e) == 0) {
            return cont;
        }
    }
    return -1;
}

bool containsStack(Stack s, void *e) {
    return searchStack(s, e) != -1;
}

void** stackToArray(Stack s) {
    int cont;
    if (s.size == 0) {
        return malloc(0);
    }
    void **array = (void**) malloc (s.size * sizeof(void*));

    for (cont = 0; cont < s.size; cont++) {
        array[cont] = s.data[cont];
    }
    return array;
}

bool equalsStack(Stack s1, Stack s2) {
    int cont;

    if (s1.size != s2.size) {
        return false;
    }
    for (cont = 0; cont < s1.size; cont++) {
        if (s1.compare(s1.data[cont], s2.data[cont]) != 0) {
            return false;
        }
    }
    return true;
}