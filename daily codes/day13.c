#include <stdio.h>

double findMedian(int nums1[], int m, int nums2[], int n) {

    int total = m + n;
    int i = 0, j = 0;
    int count = 0;

    int current = 0;
    int previous = 0;

    // We only need to process elements up to the middle
    while (count <= total / 2) {

        previous = current;

        // Select smaller element from the two arrays
        if (i < m && (j >= n || nums1[i] <= nums2[j])) {
            current = nums1[i];
            i++;
        }
        else {
            current = nums2[j];
            j++;
        }

        count++;
    }

    // If total number of elements is odd
    if (total % 2 == 1) {
        return current;
    }

    // If total number of elements is even
    return ((double)previous + current) / 2.0;
}

int main() {

    int m, n;

    printf("Enter size of first array: ");
    scanf("%d", &m);

    int nums1[m];

    printf("Enter elements of first sorted array:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n);

    int nums2[n];

    printf("Enter elements of second sorted array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    double median = findMedian(nums1, m, nums2, n);

    printf("Median = %.2f\n", median);

    return 0;
}