#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k - 1)
            return arr[pivotIndex];

        if (pivotIndex > k - 1)
            return quickSelect(arr, low, pivotIndex - 1, k);

        return quickSelect(arr, pivotIndex + 1, high, k);
    }

    return -1;
}

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    if (k < 1 || k > n) {
        printf("Invalid value of k\n");
        return 0;
    }

    int result = quickSelect(arr, 0, n - 1, k);

    printf("%dth largest element = %d\n", k, result);

    return 0;
}