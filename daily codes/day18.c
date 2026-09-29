#include <stdio.h>

int removeDuplicates(int arr[], int n)
{
    if (n == 0)
        return 0;

    int k = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[k - 1])
        {
            arr[k] = arr[i];
            k++;
        }
    }

    return k;
}

int main()
{
    int arr[] = {1, 1, 2, 3, 3, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = removeDuplicates(arr, n);

    printf("k = %d\n", k);
    printf("Array after removing duplicates: ");

    for (int i = 0; i < k; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}