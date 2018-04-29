/**
 * Exercise 13.2
 *
 * Write a function called monthName() that takes as its argument a
 * value of type enum month(as defined in this chapter) and returns
 * a pointer to a character string containing the name of the month.
 * In this way, you can display the value of an enum month variable
 * with a statement such as: printf ("%s\n", monthName (aMonth));
 */

#include <stdio.h>

enum month
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};


char *monthNames[12] =
{
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

char * monthName (enum month aMonth)
{
    return monthNames[aMonth - 1];
}

int main()
{
	/* print out all the example months */
    int i;
    for (i = 1; i <= 12; ++i)
        printf("%s\n", monthName(i));
    return 0;
}
