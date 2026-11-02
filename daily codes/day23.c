#include <stdio.h>

#define MAX 100

void bucketSort(int arr[], int n) {
    int buckets[10][MAX];
    int bucketCount[10] = {0};

    // Find maximum element
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] * 9) / max;

        buckets[bucketIndex][bucketCount[bucketIndex]] = arr[i];
        bucketCount[bucketIndex]++;
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < 10; i++) {

        for (int j = 1; j < bucketCount[i]; j++) {

            int key = buckets[i][j];
            int k = j - 1;

            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }

            buckets[i][k + 1] = key;
        }
    }

    // Combine all buckets
    int index = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int arr[] = {42, 32, 33, 52, 37, 47, 51};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucketSort(arr, n);

    printf("\nSorted Array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}