#include <stdio.h>

int trapWater(int height[], int n) {

    int left = 0;
    int right = n - 1;

    int leftMax = 0;
    int rightMax = 0;

    int water = 0;

    while (left < right) {

        // Process the smaller side
        if (height[left] <= height[right]) {

            // Update maximum height on left side
            if (height[left] >= leftMax) {
                leftMax = height[left];
            }
            else {
                // Water trapped at current position
                water += leftMax - height[left];
            }

            left++;
        }
        else {

            // Update maximum height on right side
            if (height[right] >= rightMax) {
                rightMax = height[right];
            }
            else {
                // Water trapped at current position
                water += rightMax - height[right];
            }

            right--;
        }
    }

    return water;
}

int main() {

    int n;

    printf("Enter number of bars: ");
    scanf("%d", &n);

    int height[n];

    printf("Enter heights of bars:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    int result = trapWater(height, n);

    printf("Total trapped water = %d\n", result);

    return 0;
}