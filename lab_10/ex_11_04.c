/**
 * Exercise 11.4
 *
 * Using the result obtained in exercise 3, modify the rotate() function from
 * Program 11.4 so that it no longer makes any assumptions about the size of an
 * int.
 */

#include <stdio.h>

int int_size()
{

    unsigned int x = ~0;
    unsigned int i = 0;
    while ((x >>= 1) != 0)
        i++;
    return i + 1;
}

/* convert int to binary string repr in char buffer */
char * int2bin(unsigned int a, char * buffer)
{
    const unsigned int intsize = int_size();
    char * start = buffer;
    buffer += (intsize - 1);
    /* slide buffer back to start while bitshifting a forwards it extract the
     * next LSB
     */
    while(buffer >= start)
    {
        *buffer-- = (a & 1) + '0';
        a >>= 1;
    }
    return start;
}

unsigned int rotate (unsigned int value, int n)
{
    unsigned int result, bits;
    /* get tha number of bits in an int with the int_size() function */
    const unsigned char intsize = int_size();

    /* scale down the shift count to a defined range */
    if ( n > 0 )
        n = n % intsize;
    else
        n = -(-n % intsize);

    if ( n == 0 )
        result = value;
    else if ( n > 0 )
    {
        /* left rotate */
        bits = value >> (intsize - n);
        result = value << n | bits;
    }
    else
    {
        /* right rotate */
        n = -n;
        bits = value << (intsize - n);
        result = value >> n | bits;
    }
    return result;
}

int main()
{
    const unsigned int x = 0xd8133609;
    /* allocate a string for printing binary repr */
    char binstring[33];
    /* set the null terminator so printf stops */
    binstring[32] = 0;
    /* print the number we're rotating */
    printf("%X\n", x);
    unsigned char i;
    /* print a bunch of results: one for each rotation */
    for (i = 0; i < 64; ++i)
        printf("%s\n", int2bin(rotate(x, i), binstring));
    return 0;
}
