/**
 * Exercise 10.5
 *
 * A doubly linked list is a list in which each entry contains a pointer to the
 * preceding entry in the list as well as a pointer to the next entry in the
 * list. Define the appropriate structure definition for a doubly linked list
 * entry and then write a small program that implements a small doubly linked
 * list and prints out the elements of the list.
 */

#include <stdio.h>

/* struct entry contains pointers to the next element in the list and the
 * previous element in the list to allow for the creation of doubly linked
 * lists.
 */
struct entry
{
    unsigned int value;
    struct entry * previous;
    struct entry * next;
};

void printLinkedList(struct entry first)
{
    /* traverse the linked list printing values along the way until the NULL
     * pointer is reached.
     */
    while (first.next)
    {
        printf("%d->", first.value);
        first = *first.next;
    }
    printf("%d", first.value);
}

void printDLLBackward(struct entry last)
{
    /* traverse the doubly linked list backwards, printing values along the way
     * until the nullptr is reached
     */
    while (last.previous)
    {
        printf("%d<-", last.value);
        last = *last.previous;
    }
    printf("%d", last.value);
}

int main()
{
    struct entry a[10];
    int i;
    for (i = 0; i < 10; ++i)
    {
        a[i].value = i; /* initialize values */
        a[i].next = &a[(i + 1) % 10]; /* forward links */
        a[i].previous = &a[(i - 1) % 10]; /* backward links */
    }

    /* list is now circular, break it at the beginning and end with nullptr
     * terminators.
     */
    a[0].previous = a[9].next = NULL;

    /* print the list by traversing forward and backward. */
    printLinkedList(a[0]);
    putchar('\n');
    printDLLBackward(a[9]);
    putchar('\n');
    return 0;
}
