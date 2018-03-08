/*
 * Exercise 6.3
 * Program 6.2 permits only 20 responses to be entered. Modify that program so
 * that any number of responses can be entered. So that the user does not have
 * to count the number of responses in the list, set up the program so that the
 * value 999 can be keyed in by the user to indicate that the last response has
 * been entered. (Hint: You can use the break statement here if you want to
 * exit your loop.)
 */

#include <stdio.h>
int main (void)
{
    int ratingCounters[11], i, response = 0;

    /* initialize the array with 0 */
    for ( i = 1; i <= 10; ++i )
        ratingCounters[i] = 0;

    /* prompt user to enter responses*/
    printf ("Enter your responses\n");


    /* always poll until user enters 999 to exit */
    while (1)
    {
        /* read the users response into the `response` varaible */
        scanf ("%i", &response);

        if (response == 999)
            /* break the loop when user enters 999 to exit */
            break;
        else if ( response < 1 || response > 10 )
            /* if user enters a bad response warn and continue */
            printf ("Bad response: %i\n", response);
        else
            /* valid response given, increment selected counter and continue */
            ++ratingCounters[response];
    }

    /* print the distribution of results */

    printf ("\n\nRating Number of Responses\n");
    printf ("------ -------------------\n");

    for ( i = 1; i <= 10; ++i )
        printf ("%4i%14i\n", i, ratingCounters[i]);
    return 0;
}
