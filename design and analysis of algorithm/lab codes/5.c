#include <stdio.h>

int main() {
    int n, i;
    int start[20], finish[20];

    printf("Enter number of activities: ");
    scanf("%d", &n);

    printf("Enter start and finish times:\n");

    for (i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    // Sort activities according to finish time
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (finish[i] > finish[j]) {
                int temp;

                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }

    printf("\nSelected Activities:\n");

    // Select first activity
    printf("(%d, %d)\n", start[0], finish[0]);

    int last = 0;

    for (i = 1; i < n; i++) {
        // Check if current activity starts
        // after or when previous activity finishes
        if (start[i] >= finish[last]) {
            printf("(%d, %d)\n", start[i], finish[i]);
            last = i;
        }
    }

    return 0;
}