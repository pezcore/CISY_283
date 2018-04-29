/**
 * Exercise 9.4
 *
 * Write a function called `substring()` to extract a portion of a character
 * string. The function should be called as follows:
 *
 *  substring (source, start, count, result);
 *
 * where `source` is the character string from which you are extracting the
 * substring, `start` is an index number into `source` indicating the first
 * character of the substring , `count` is the number of characters to be
 * extracted from the source string, and `result` is an array of characters
 * that is to contain the extracted substring.For example, the call
 *
 *  substring ("character", 4, 3, result);
 *
 * extracts the substring "act" (three characters starting with character
 * number 4) from the string "character" and places the result in result. Be
 * certain the function inserts a null character at the end of the substring in
 * the result array. Also, have the function check that the requested number of
 * characters does, in fact, exist in the string. If this is not the case, have
 * the function end the substring when it reaches the end of the source string.
 * So, for example, a call such as
 *
 *  substring ("two words", 4, 20, result);
 *
 * should just place the string "words" inside the result array, even though 20
 * characters were requested by the call.
 */

#include <stdio.h>

void substring(const char *, int, int, char *);

int main()
{
    /* allocate a char array for the buffer */
    char buffer[1024];

    /* test the function with "character" as per example */
    substring("character", 4, 3, buffer);
    printf("substring(\"character\", 4, 3, buffer);\n");
    printf("%s\n", buffer);

    /* test the function with "two words" as per example */
    substring("two words", 4, 20, buffer);
    printf("substring(\"two words\", 4, 20, buffer);\n");
    printf("%s\n", buffer);
    return 0;
}

/**
 * copy the substring having at most `count` bytes and starting at index
 * `start` from `source` into `result`
 */
void substring(const char * source, int start, int count, char * result)
{
    /* declare and initialize destination write head */
    int i = 0;

    /* write chars from source to dest iteratively decrementing the counter
     * on each iteration and keeping the src and destination heads in lockstep
     * until the counter is exhausted or a '\0' is found
     */
    while (count-- && (result[i++] = source[start++]))
        ;

    /* append the terminating '\0' at the end in case the while loop above was
     * terminated by exhausting the counter. If it was terminated early by
     * reaching the end of the source string, this last step will be
     * unnecessary, but will also be outside the result string so just do it
     * anyway because it's cheap and harmless.
     */
    result[i] = '\0';
}
