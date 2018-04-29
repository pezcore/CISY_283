/**
 * Exercise 11.7
 *
 * Write a function called bitpat_get() to extract a specified set of bits.
 * Have it take three arguments: the first an unsigned int , the second an
 * integer starting bit number, and the third a bit count. Using the convention
 * that bit numbering starts at 0 with the leftmost bit, extract the specified
 * number of bits from the first argument and return the result. So the call
 *
 *  bitpat_get (x, 0, 3)
 *
 * extracts the three leftmost bits from x.  The call
 *
 *  bitpat_get (x, 3, 5)
 *
 * extracts five bits starting with the fourth bit in from the left.
 */

#include <stdio.h>
#include <limits.h>
#define INT_WIDTH sizeof(int) * CHAR_BIT

unsigned int bitpat_get(unsigned int x, int start, int count)
{
    return x << start >> (INT_WIDTH - count);
}

int main()
{
    /* Test vector :
     *             0    5    10   15   20   25   31
     *             |    |    |    |    |    |    |
     * binary is 0b11011000000100110011011000001001
     */
    const unsigned int x = 0xD8133609;
    int i, j;
    for (i = 0; i < 31; ++i)
        for (j = 0; j < 31; ++j)
            printf("%2d %2d %u\n", i, j, bitpat_get(x, i, j));
    return 0;
}
