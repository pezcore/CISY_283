/**
 * Exercise 10.4
 *
 * Write a function called `removeEntry()` to remove an entry from a linked
 * list.  The sole argument to the procedure should be a pointer to the list.
 * Have the function remove the entry after the one pointed to by the argument.
 * (Why can’t you remove the entry pointed to by the argument?) You need to use
 * the special structure you set up in exercise 3 to handle the special case of
 * removing the first element from the list.
 */

/**
 * Question explanation
 *
 * The element pointed to directly by the argument to `removeEntry()` can not
 * be removed in the singly linked list case because in order to re-link the
 * list after element removal, access to the previous element is required.
 * However in a singly linked list links only traverse the list in one
 * direction and therefore the previous element is not accessible from the
 * argument.
 */

#include <stdio.h>

/* define the struct entry type */
struct entry
{
    unsigned int value;
    struct entry * next;
};

/**
 * Remove an entry from a linked list
 */
void removeEntry(struct entry *);

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
     * printLinkedList()
     */
    printf("Original linked list:\n");
    printLinkedList(a[0]);
    putchar('\n');

    /* A dummy entry is kept to allow for removal of the first element in the
     * array list. This dummy variable is an entry that points to the beginning
     * of the array list via it's `next` pointer, but isn't actually considered
     * part of the list by any any of the list's clients. The dummy serves as a
     * placeholder to allow for removal of the first element of the list.
     * Clients are required to keep the dummy element tracking the first
     * element of the linked list.
     */
    struct entry dummy = {0, &a[0]};

    /* remove an element by calling removeEntry() */
    removeEntry(&a[4]);

    printf("Linked list after removal of 5 element:\n");
    printLinkedList(a[0]);
    putchar('\n');

    /* demonstrate removing the first element by calling removeEntry() on the
     * dummy
     */
    removeEntry(&dummy);
    printf("Linked list after removal of 0 element:\n");
    printLinkedList(*dummy.next);
    putchar('\n');

    return 0;
}

void removeEntry(struct entry * rem_after)
{
    /* remove an element by making the links skip over it. */
    rem_after->next = rem_after->next->next;
}

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
