#include <stdio.h>

int main()
{
    int a[] = {10, 12, 15, 14, 16, 18, 20};
    int n = 7;

    int current = 1;
    int longest = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            current++;
        }
        else
        {
            current = 1;
        }

        if (current > longest)
        {
            longest = current;
        }
    }

    printf("Longest increasing streak = %d\n", longest);

    return 0;
}