#include <stdio.h>

int findSingle(int nums[], int n) {
    int low = 0;
    int high = n - 1;

    while (low < high) {

        int mid = low + (high - low) / 2;

        // Make mid even so that we can compare pairs
        if (mid % 2 == 1) {
            mid--;
        }

        // If pair is correct, single element is on right side
        if (nums[mid] == nums[mid + 1]) {
            low = mid + 2;
        }
        // Otherwise single element is on left side
        else {
            high = mid;
        }
    }

    return nums[low];
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the sorted array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = findSingle(nums, n);

    printf("Single element = %d\n", result);

    return 0;
}