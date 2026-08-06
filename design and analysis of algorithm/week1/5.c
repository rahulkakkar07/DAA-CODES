#include <stdio.h>

#define MAX 50

int main()
{
    int a[MAX][MAX], b[MAX][MAX], product[MAX][MAX];
    int arows, acols, brows, bcols;
    int i, j, k;
    int sum;

    // Input matrix A
    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &arows, &acols);

    printf("Enter the elements of matrix A:\n");
    for(i = 0; i < arows; i++)
    {
        for(j = 0; j < acols; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Input matrix B
    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &brows, &bcols);

    // Check compatibility
    if(acols != brows)
    {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    printf("Enter the elements of matrix B:\n");
    for(i = 0; i < brows; i++)
    {
        for(j = 0; j < bcols; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Matrix Multiplication
    for(i = 0; i < arows; i++)
    {
        for(j = 0; j < bcols; j++)
        {
            sum = 0;

            for(k = 0; k < acols; k++)
            {
                sum += a[i][k] * b[k][j];
            }

            product[i][j] = sum;
        }
    }

    // Display Result
    printf("\nResultant Matrix is:\n");

    for(i = 0; i < arows; i++)
    {
        for(j = 0; j < bcols; j++)
        {
            printf("%d\t", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}