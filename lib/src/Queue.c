#include "Queue.h"

static Node* createNode(void *e) {
    Node *n = (Node*) malloc (sizeof(Node));
    if (!n) {
        fprintf(stderr, "Error: No memory available\n");
        exit(1);
    }

    n->data = e;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void createQueue(Queue *q, compare_func compare, print_func print) {
    q->size = 0;
    q->first = NULL;
    q->last = NULL;
    q->compare = compare;
    q->print = print;
}

void deleteQueue(Queue *q) {
    Node *current = q->first, *next;
    compare_func compare = q->compare;
    print_func print = q->print;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    createQueue(q, compare, print);
}

void clearQueue(Queue *q) {
    deleteQueue(q);
}

int sizeQueue(Queue q) {
    return q.size;
}

bool isEmptyQueue(Queue q) {
    return q.size == 0;
}

void printQueue(Queue q) {
    Node *current = q.first;
    int cont = 1;

    if (q.size == 0) {
        printf("Empty Queue.\n");
    } else {
        printf("Queue:\n");
        while (current != NULL) {
            printf("Element %d: ", cont);
            q.print(current->data);
            current = current->next;
            cont++;
        }
    }
}

void enqueue(Queue *q, void *e) {
    Node *n = createNode(e);

    if (q->size == 0) {
        q->first = n;
        q->last = n;
    } else {
        q->last->next = n;
        n->prev = q->last;
        q->last = n;
    }
    q->size++;
}

void enqueueArray(Queue *q, void **array, int n) {
    int cont;

    for (cont = 0; cont < n; cont++) {
        enqueue(q, array[cont]);
    }
}

void enqueueQueue(Queue *destination, Queue origin) {
    Node *current = origin.first;

    while (current != NULL) {
        enqueue(destination, current->data);
        current = current->next;
    }
}

void* dequeue(Queue *q) {
    Node *toRemove;
    void *data;

    if (q->size == 0) {
        return NULL;
    }
    toRemove = q->first;
    data = toRemove->data;
    if (q->size == 1) {
        q->first = NULL;
        q->last = NULL;
    } else {
        q->first = q->first->next;
        q->first->prev = NULL;
    }
    free(toRemove);
    q->size--;
    return data;
}

void** dequeueNElements(Queue *q, int n) {
    int cont;

    if (q->size == 0) {
        return NULL;
    } else if (q->size - n < 0) {
        n = q->size;
    }
    void **array = (void**) malloc (n * sizeof(void*));

    for (cont = 0; cont < n; cont++) {
        array[cont] = dequeue(q);
    }
    return array;
}

void* getQueue(Queue q, int index) {
    Node *current = q.first;
    int cont = 0;

    if (q.size == 0 || index >= q.size || index < 0) {
        return NULL;
    }
    while (current != NULL) {
        if (cont == index) {
            return current->data;
        }
        current = current->next;
        cont++;
    }
    return NULL;
}

void* getFirstQueue(Queue q) {
    if (q.size == 0) {
        return NULL;
    }
    return q.first->data;
}

void* getLastQueue(Queue q) {
    if (q.size == 0) {
        return NULL;
    }
    return q.last->data;
}

void* front(Queue q) {
    if (q.size == 0) {
        return NULL;
    }
    return q.first->data;
}

void* back(Queue q) {
    if (q.size == 0) {
        return NULL;
    }
    return q.last->data;
}

int searchQueue(Queue q, void *e) {
    Node *current = q.first;
    int pos = 0;

    while (current != NULL) {
        if (q.compare(current->data, e) == 0) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;
}

bool containsQueue(Queue q, void *e) {
    return searchQueue(q, e) != -1;
}

void** queueToArray(Queue q) {
    int cont;
    Node *current = q.first;

    if (q.size == 0) {
        return NULL;
    }
    void **array = (void**) malloc (q.size * sizeof(void*));

    for (cont = 0; cont < q.size; cont++) {
        array[cont] = current->data;
        current = current->next;
    }
    return array;
}

bool equalsQueue(Queue q1, Queue q2) {
    Node *current1 = q1.first, *current2 = q2.first;

    if (q1.size != q2.size) {
        return false;
    }
    while (current1 != NULL) {
        if (q1.compare(current1->data, current2->data) != 0) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return true;
}