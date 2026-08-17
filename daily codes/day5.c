#include <stdio.h>

int main()
{
    int n, bit;
    int ones = 0, zeros = 0;
    int current = 0, max = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 0)
    {
        bit = n % 2;

        if (bit == 1)
        {
            ones++;
            current++;

            if (current > max)
                max = current;
        }
        else
        {
            zeros++;
            current = 0;
        }

        n = n / 2;
    }

    printf("Number of 1s: %d\n", ones);
    printf("Number of 0s: %d\n", zeros);
    printf("Maximum consecutive 1s: %d\n", max);

    return 0;
}