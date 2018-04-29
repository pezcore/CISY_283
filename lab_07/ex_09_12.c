/**
 * Exercise 9.12
 * Write a function called strToFloat() that converts a character string into a
 * floating-point value. Have the function accept an optional leading minus
 * sign. So, the call
 *
 *  strToFloat ("-867.6921");
 *
 * should return the value −867.6921.
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

float strToFloat(const char *);

int main()
{
    /* test positive and negative numbers */
    printf("%f\n", strToFloat("1.4234"));
    printf("%f\n", strToFloat("-867.6921"));

    /* with 0 integer parts */
    printf("%f\n", strToFloat("0.1234"));
    printf("%f\n", strToFloat("-0.5432"));

    /* with 0 integer parts and omitted leading zero */
    printf("%f\n", strToFloat(".6789"));
    printf("%f\n", strToFloat("-.0987"));
    return 0;
}

float strToFloat(const char * s)
{
    /* The significand. Floats require 23 bits of mantissa so use uint32_t to
     * guarantee it's wide enough */
    uint32_t manitssa;
    uint32_t denominator;
    int sign = 1;   /* sign of argument */

    /* check first char to see if number is negative */
    if (*s == '-')
    {
        sign = -1;
        ++s;
    }

    /* while chars are digits, start filling out the mantissa */
    for (manitssa = 0; *s && isdigit(*s); ++s)
        manitssa = manitssa * 10 + (*s - '0');

    /* skip over the radix point, assuming this is the only non-digit in the
     * middle of the string */
    ++s;

    /* continue filling out the mantissa but also count the denominator
     * exponent because radix point is past */
    for (denominator = 1; *s && isdigit(*s); ++s, denominator *= 10)
        manitssa = manitssa * 10 + (*s - '0');

    /* cast numerator to float so we get true divide */
    return (float) manitssa * sign / denominator;
}
