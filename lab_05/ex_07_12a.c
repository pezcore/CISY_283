/*
 * Exercise 7.12a
 * A matrix M with i rows, j columns can be transposed into a matrix N having j
 * rows and i columns by simply setting the value of N[a,b] equal to the value
 * of M[b,a] for all relevant values of a and b. Write a function
 * transposeMatrix() that takes as an argument a 4 × 5 matrix and a 5 × 4
 * matrix. Have the function transpose the 4 × 5 matrix and store the results
 * in the 5 × 4 matrix. Also write a main() routine to test the function.
 */

#include <stdio.h>

/* forward declare functions */
void transposeMatrix(int[4][5], int[5][4]);
void printMatrix(int*, int, int);

int main()
{
    int in[4][5] = {{1, 2, 3, 4, 5},
                    {6, 7, 8, 9, 10},
                    {11, 12, 13, 14, 15},
                    {16, 17, 18, 19, 20}};
    int out[5][4];
    printf("Input:\n");
    printMatrix(&in[0][0], 4, 5);
    /* call the transpose to fill the ouput */
    transposeMatrix(in, out);
    printf("Output:\n");
    printMatrix(&out[0][0], 5, 4);
    return 0;
}

void printMatrix(int* arr, const int rows, const int cols)
{
    int i, j;
    /* pretty print a 2d array */
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            /* use ptr arith */
            printf("%2d ", arr[i * cols + j]);
        }
        printf("\n");
    }
    putchar('\n');
}

void transposeMatrix(int in[4][5], int out[5][4])
{
    int i, j;
    /* for every element, put the output in the revere order index as the
     * input*/
    for (i = 0; i < 4; ++i)
        for (j = 0; j < 5; ++j)
            out[j][i] = in[i][j];
}
