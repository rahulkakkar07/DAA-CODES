#include <stdio.h>

void sortArrayByParity(int nums[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {

        // If left is odd and right is even, swap them
        if (nums[left] % 2 != 0 && nums[right] % 2 == 0) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;

            left++;
            right--;
        }

        // Move left if it already contains an even number
        if (nums[left] % 2 == 0)
            left++;

        // Move right if it already contains an odd number
        if (nums[right] % 2 != 0)
            right--;
    }
}

int main() {
    int nums[] = {3, 1, 2, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    sortArrayByParity(nums, n);

    printf("Output: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}