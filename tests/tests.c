#include <string.h>
#include "Stack.h"
#include "Queue.h"
#include "unity.h"

typedef struct {
    char *name;
    char *surname;
} Person;

int currentSturcture = 0;
Stack s1, s2;
Queue q1, q2;
Person p1, p2, p3, p4, p5;

void createPerson(Person *p, char *name, char *surname);
int peopleComparator(const void *p1, const void *p2);
void printPerson(const void *p);
void freePerson(Person *p);

void setUp() {
    createPerson(&p1, "Adam", "Smith");
    createPerson(&p2, "Will", "Smith");
    createPerson(&p3, "Adam", "Williams");
    createPerson(&p4, "Sarah", "Sanchez");
    createPerson(&p5, "Samantha", "James");

    createStack(&s1, peopleComparator, printPerson);
    createStackWithCapacity(&s2, 16, peopleComparator, printPerson);
    push(&s1, &p1);

    createQueue(&q1, peopleComparator, printPerson);
    createQueue(&q2, peopleComparator, printPerson);
    enqueue(&q1, &p1);
}

void test_size() {
    switch (currentSturcture) {
        case 0:
            TEST_ASSERT_EQUAL_INT(1, sizeStack(s1));
            TEST_ASSERT_EQUAL_INT(0, sizeStack(s2));
            break;
        case 1:
            TEST_ASSERT_EQUAL_INT(1, sizeQueue(q1));
            TEST_ASSERT_EQUAL_INT(0, sizeQueue(q2));
            break;
        default:
            break;
    }
}

void test_isEmpty() {
    switch (currentSturcture) {
        case 0:
            TEST_ASSERT_FALSE(isEmptyStack(s1));
            TEST_ASSERT_TRUE(isEmptyStack(s2));
            break;
        case 1:
            TEST_ASSERT_FALSE(isEmptyQueue(q1));
            TEST_ASSERT_TRUE(isEmptyQueue(q2));
            break;
        default:
            break;
    }
}

void test_add_element() {
    int cont;
    void *array[2] = {&p4, &p5};
    Person result[6] = {p1, p2, p3, p4, p5, p1};

    switch (currentSturcture) {
        case 0:
            push(&s1, &p2);
            push(&s1, &p3);
            pushArray(&s1, array, 2);
            push(&s2, &p1);
            pushStack(&s1, s2);

            TEST_ASSERT_EQUAL_INT(6, sizeStack(s1));
            TEST_ASSERT_FALSE(isEmptyStack(s1));
            for (cont = 0; cont < sizeStack(s1); cont++) {
                TEST_ASSERT_EQUAL_INT(0, peopleComparator(getStack(s1, cont), &result[cont]));
            }
            break;
        case 1:
            enqueue(&q1, &p2);
            enqueue(&q1, &p3);
            enqueueArray(&q1, array, 2);
            enqueue(&q2, &p1);
            enqueueQueue(&q1, q2);

            TEST_ASSERT_EQUAL_INT(6, sizeQueue(q1));
            TEST_ASSERT_FALSE(isEmptyQueue(q1));
            for (cont = 0; cont < sizeQueue(q1); cont++) {
                TEST_ASSERT_EQUAL_INT(0, peopleComparator(getQueue(q1, cont), &result[cont]));
            }
            break;
        default:
            break;
    }
}

void test_remove_elements() {
    void *removedElement;
    void **removedArray;

    switch (currentSturcture) {
        case 0:
            pop(&s2);
            TEST_ASSERT_TRUE(isEmptyStack(s2));
            TEST_ASSERT_NULL(pop(&s2));
            TEST_ASSERT_NULL(popNElements(&s2, 3));

            removedArray = popNElements(&s1, 3);
            TEST_ASSERT_EQUAL_INT(3, sizeStack(s1));
            TEST_ASSERT_EQUAL_INT(0, peopleComparator(&p1, removedArray[0]));
            TEST_ASSERT_EQUAL_INT(0, peopleComparator(&p5, removedArray[1]));
            TEST_ASSERT_EQUAL_INT(0, peopleComparator(&p4, removedArray[2]));
            break;
        case 1:
            dequeue(&q2);
            TEST_ASSERT_TRUE(isEmptyQueue(q2));
            TEST_ASSERT_NULL(dequeue(&q2));
            TEST_ASSERT_NULL(dequeueNElements(&q2, 3));

            removedArray = dequeueNElements(&q1, 3);
            TEST_ASSERT_EQUAL_INT(3, sizeQueue(q1));
            TEST_ASSERT_EQUAL_INT(0, peopleComparator(&p1, removedArray[0]));
            TEST_ASSERT_EQUAL_INT(0, peopleComparator(&p2, removedArray[1]));
            TEST_ASSERT_EQUAL_INT(0, peopleComparator(&p3, removedArray[2]));
            break;
        default:
            break;
    }
}

void test_search() {
    switch(currentSturcture) {
        case 0:
            push(&s1, &p4);
            push(&s1, &p5);
            TEST_ASSERT_EQUAL_INT(0, searchStack(s1, &p1));
            TEST_ASSERT_EQUAL_INT(1, searchStack(s1, &p2));
            TEST_ASSERT_EQUAL_INT(2, searchStack(s1, &p3));
            TEST_ASSERT_EQUAL_INT(3, searchStack(s1, &p4));
            TEST_ASSERT_EQUAL_INT(4, searchStack(s1, &p5));
            pop(&s1);
            TEST_ASSERT_EQUAL_INT(-1, searchStack(s1, &p5));
            break;
        case 1:
            enqueue(&q1, &p2);
            enqueue(&q1, &p3);
            TEST_ASSERT_EQUAL_INT(2, searchQueue(q1, &p1));
            TEST_ASSERT_EQUAL_INT(3, searchQueue(q1, &p2));
            TEST_ASSERT_EQUAL_INT(4, searchQueue(q1, &p3));
            TEST_ASSERT_EQUAL_INT(0, searchQueue(q1, &p4));
            TEST_ASSERT_EQUAL_INT(1, searchQueue(q1, &p5));
            dequeue(&q1);
            TEST_ASSERT_EQUAL_INT(-1, searchQueue(q1, &p4));
        default:
            break;
    }
}

void test_equals() {
    switch(currentSturcture) {
        case 0:
            TEST_ASSERT_TRUE(isEmptyStack(s2));
            pushStack(&s2, s1);
            TEST_ASSERT_TRUE(equalsStack(s1, s2));
            pop(&s1);
            TEST_ASSERT_FALSE(equalsStack(s1, s2));
            break;
        case 1:
            TEST_ASSERT_TRUE(isEmptyQueue(q2));
            enqueueQueue(&q2, q1);
            TEST_ASSERT_TRUE(equalsQueue(q1, q2));
            dequeue(&q1);
            TEST_ASSERT_FALSE(equalsQueue(q1, q2));
        default:
            break;
    }
}

void tearDown() {
    deleteStack(&s1);
    deleteStack(&s2);

    deleteQueue(&q1);
    deleteQueue(&q2);

    freePerson(&p1);
    freePerson(&p2);
    freePerson(&p3);
    freePerson(&p4);
    freePerson(&p5);
}

void testsStructure() {
    RUN_TEST(test_size);
    RUN_TEST(test_isEmpty);
    RUN_TEST(test_add_element);
    RUN_TEST(test_remove_elements);
    RUN_TEST(test_search);
    RUN_TEST(test_equals);
    currentSturcture++;
}

int main() {
    UNITY_BEGIN();
    setUp();

    testsStructure();
    testsStructure();


    tearDown();
    return UNITY_END();
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