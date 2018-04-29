/**
 * Exercise 10.6
 *
 * Develop `insertEntry()` and `removeEntry()` functions for a doubly linked
 * list that are similar in function to those developed in previous exercises
 * for a singly linked list. Why can your removeEntry() function now take as
 * its argument a direct pointer to the entry to be removed from the list?
 */

/**
 * Question Explanation:
 *
 * In the case of a doubly linked list, the element preceding the one to be
 * removed is now accessable via the links from the element to be removed so it
 * is possbile to obtain both the preceding and following elements and
 * therefore it is possible to remove the element specified by the argument and
 * relink the doubly linked list appropriately. This is illustrated in
 * `removeEntry()`.
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

void insertEntry(struct entry * insert_me, struct entry * after_me)
{
    /* set the pointers for the item to be inserted */
    insert_me->previous = after_me;
    insert_me->next = after_me->next;
    /* set the foward and backward pointers for the preceding and following
     * entries
     */
    after_me->next = insert_me;
    insert_me->next->previous = insert_me;
}

void removeEntry(struct entry * remove_me)
{
    /* set the preceding element's next pointer to the following element */
    remove_me->previous->next = remove_me->next;
    /* set the following element's pervious pointer to the preceding element */
    remove_me->next->previous = remove_me->previous;
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

    /* print the original linked list with both forward and backward traversal
     * using the helper function.
     */
    printf("Original linked list:\n");
    printLinkedList(a[0]);
    putchar('\n');
    printDLLBackward(a[9]);
    putchar('\n');

    /* define a new entry to be inserted into the doubly linked list */
    struct entry newEntry = {0xff, 0};
    /* insert it by calling insertEntry */
    insertEntry(&newEntry, &a[5]);

    /* print the list foward and backward after the insertion */
    printf("Linked list after insertion of 0xff:\n");
    printLinkedList(a[0]);
    putchar('\n');
    printDLLBackward(a[9]);
    putchar('\n');

    /* remove the 8 entry from the linked with  the removeEntry() function */
    removeEntry(&a[8]);

    /* print the list again forward and backward */
    printf("Linked list after removal of 8:\n");
    printLinkedList(a[0]);
    putchar('\n');
    printDLLBackward(a[9]);
    putchar('\n');
    return 0;
}
