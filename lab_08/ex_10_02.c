/**
 * Exercise 10.2
 *
 * Write a function called `insertEntry()` to insert a new entry into a linked
 * list. Have the procedure take as arguments a pointer to the list entry to be
 * inserted (of type struct entry as defined in this chapter), and a pointer to
 * an element in the list after which the new entry is to be inserted.
 */

#include <stdio.h>


/* define the struct entry type */
struct entry
{
    unsigned int value;
    struct entry * next;
};

/**
 * Insert a new entry into a linked list.
 */
void insertEntry(struct entry *, struct entry *);

/**
 * print a linked list by traversing the elements until the end is reached
 */
void printLinkedList(struct entry first);

int main()
{
    /* define array to hold elements of the original linked list */
    struct entry a[10];

    /* initialized the elements to store values 0..9 and link them together
     * sequentially
     */
    int i;
    for (i = 0; i < 10; ++i)
    {
        a[i].value = i;
        a[i].next = &a[i + 1];
    }

    /* set the last element's pointer to NULL so that traversal algorithms will
     * stop at the end of the linked list and avoid SEGFAULT. Use constant 9
     * (instead of variable i) to avoid stack smashing
     */
    a[9].next = NULL;

    /* print the original linked list using the convenience function
     * printLinkedList
     */
    printf("Original linked list:\n");
    printLinkedList(a[0]);
    putchar('\n');

    /* delcare and initialize the element to be inserted into the linked list
     */
    struct entry insert_me = {0xffff, NULL};
    insertEntry(&insert_me, &a[5]);

    /* print the values in the linked list after the insertion operation to
     * show the result is as expected
     */
    printf("Linked list after insertion of %d:\n", insert_me.value);
    printLinkedList(a[0]);
    putchar('\n');
    return 0;
}

void insertEntry(struct entry * insert_me, struct entry * after_me)
{
    /* simple array list insertion routine: swap and replace pointers */
    insert_me->next = after_me->next;
    after_me->next = insert_me;
}

void printLinkedList(struct entry first)
{
    /* travese the linked list printing values along the way until the NULL
     * pointer is reached.
     */
    while (first.next)
    {
        printf("%d->", first.value);
        first = *first.next;
    }
    printf("%d", first.value);
}
