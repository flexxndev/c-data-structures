#include <string.h>
#include "Stack.h"
#include "Queue.h"

typedef struct {
    char *name;
    char *surname;
} Person;

void createPerson(Person *p, char *name, char *surname);
int peopleComparator(const void *p1, const void *p2);
void printPerson(const void *p);
void freePerson(Person *p);

void runStackDemo();
void runQueueDemo();

Person p1, p2, p3, p4, p5;

int main() {

    createPerson(&p1, "Adam", "Smith");
    createPerson(&p2, "Will", "Smith");
    createPerson(&p3, "Adam", "Williams");
    createPerson(&p4, "Sarah", "Sanchez");
    createPerson(&p5, "Samantha", "James");

    runStackDemo();
    runQueueDemo();

    freePerson(&p1);
    freePerson(&p2);
    freePerson(&p3);
    freePerson(&p4);
    freePerson(&p5);

    return 0;
}

void createPerson(Person *p, char *name, char *surname) {
    p->name = (char *) malloc (strlen(name) * sizeof(char));
    p->name = name;
    p->surname = (char *) malloc (strlen(surname) * sizeof(char));
    p->surname = surname;
}

int peopleComparator(const void *p1, const void *p2) {
    Person person1 = *(const Person*) p1;
    Person person2 = *(const Person*) p2;
    int cmpNames = strcmp(person1.name, person2.name);

    if (cmpNames == 0) {
        return strcmp(person1.surname, person2.surname);
    }
    return cmpNames;
}

void printPerson(const void *p) {
    Person person = *(const Person*) p;
    printf("%s %s\n", person.name, person.surname);
}

void freePerson(Person *p) {
    free(p->name);
    free(p->surname);
}

void runStackDemo() {

    Stack s1, s2;

    createStack(&s1, peopleComparator, printPerson);
    createStackWithCapacity(&s2, 16, peopleComparator, printPerson);

    push(&s1, &p1);
    push(&s1, &p2);
    push(&s1, &p3);
    
    push(&s2, &p4);
    push(&s2, &p5);

    printStack(s1);
    printf("Size: %d, Is empty? %s\n", sizeStack(s1), isEmptyStack(s1) ? "Yes" : "No");
    printf("Equals s1 and s2? %s\n", equalsStack(s1, s2) ? "Yes" : "No");
    pushStack(&s1, s2);
    printf("Equals s1 and s2? %s\n", equalsStack(s1, s2) ? "Yes" : "No");

    pop(&s1);
    printStack(s1);

    pop(&s1);
    printStack(s1);

    printf("%d\n", searchStack(s1, &p5));
    printf("%d\n", searchStack(s1, &p3));

    clearStack(&s1);
    printStack(s1);
    clearStack(&s2);

    deleteStack(&s1);
    deleteStack(&s2);

}

void runQueueDemo() {

    Queue q1, q2;

    createQueue(&q1, peopleComparator, printPerson);
    createQueue(&q2, peopleComparator, printPerson);

    enqueue(&q1, &p1);
    enqueue(&q1, &p2);
    enqueue(&q1, &p3);
    
    enqueue(&q2, &p4);
    enqueue(&q2, &p5);

    printQueue(q1);
    printf("Size: %d, Is empty? %s\n", sizeQueue(q1), isEmptyQueue(q1) ? "Yes" : "No");
    printf("Equals q1 and q2? %s\n", equalsQueue(q1, q2) ? "Yes" : "No");
    enqueueQueue(&q1, q2);
    printf("Equals q1 and q2? %s\n", equalsQueue(q1, q2) ? "Yes" : "No");

    dequeue(&q1);
    printQueue(q1);

    dequeue(&q1);
    printQueue(q1);

    printf("%d\n", searchQueue(q1, &p5));
    printf("%d\n", searchQueue(q1, &p3));

    clearQueue(&q1);
    printQueue(q1);
    clearQueue(&q2);

    deleteQueue(&q1);
    deleteQueue(&q2);

}