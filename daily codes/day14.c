#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m;

    printf("Enter size of first array: ");
    scanf("%d", &n);

    int arr1[n];

    printf("Enter elements of first array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &m);

    int arr2[m];

    printf("Enter elements of second array:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    int minDiff = INT_MAX;
    int num1 = 0, num2 = 0;

    // Compare every element of arr1 with every element of arr2
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            int diff = abs(arr1[i] - arr2[j]);

            if (diff < minDiff) {
                minDiff = diff;
                num1 = arr1[i];
                num2 = arr2[j];
            }
        }
    }

    printf("Smallest difference = %d\n", minDiff);
    printf("Elements are %d and %d\n", num1, num2);

    return 0;
}