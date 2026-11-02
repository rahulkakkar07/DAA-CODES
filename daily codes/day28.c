#include <stdio.h>

#define ROWS 3
#define COLS 4

int parkCar(int parking[ROWS][COLS]) {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {

            // First empty parking spot
            if (parking[i][j] == 0) {
                parking[i][j] = 1;

                printf("Car parked at Row %d, Column %d\n", i, j);
                return 1;
            }
        }
    }

    // No empty spot found
    printf("Parking is full!\n");
    return 0;
}

void displayParking(int parking[ROWS][COLS]) {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", parking[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int parking[ROWS][COLS] = {
        {1, 1, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    printf("Parking before car arrives:\n");
    displayParking(parking);

    printf("\n");

    parkCar(parking);

    printf("\nParking after car is parked:\n");
    displayParking(parking);

    return 0;
}