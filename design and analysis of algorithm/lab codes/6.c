#include <stdio.h>

struct Interval {
    int start;
    int finish;
};

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval a[n];

    printf("Enter start and finish time of each interval:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].start, &a[i].finish);
    }

    // Sort intervals according to start time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].start > a[j].start) {
                struct Interval temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    int finishTime[n];
    int room[n];
    int roomCount = 0;

    // Assign intervals to rooms
    for (int i = 0; i < n; i++) {
        int assigned = 0;

        for (int j = 0; j < roomCount; j++) {
            if (a[i].start >= finishTime[j]) {
                room[i] = j + 1;
                finishTime[j] = a[i].finish;
                assigned = 1;
                break;
            }
        }

        // Create a new room if no existing room is available
        if (!assigned) {
            finishTime[roomCount] = a[i].finish;
            room[i] = roomCount + 1;
            roomCount++;
        }
    }

    printf("\nInterval\tRoom\n");

    for (int i = 0; i < n; i++) {
        printf("%d-%d\t\t%d\n",
               a[i].start, a[i].finish, room[i]);
    }

    printf("\nMinimum number of rooms required = %d\n", roomCount);

    return 0;
}