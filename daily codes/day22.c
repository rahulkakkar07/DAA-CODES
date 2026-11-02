#include <stdio.h>

int main() {
    int arr[] = {1, 0, 2, 0, 3, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int temp[n];
    int j = 0;

    // Copy all non-zero elements
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp[j] = arr[i];
            j++;
        }
    }

    // Fill remaining positions with zero
    while (j < n) {
        temp[j] = 0;
        j++;
    }

    // Print result
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}