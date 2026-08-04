#include <stdio.h>

int main() {
    int a[50], b[50], c[100];
    int n1, n2;
    int i = 0, j = 0, k = 0;

    printf("Enter the size of first array: ");
    scanf("%d", &n1);

    printf("Enter the elements of first sorted array:\n");
    for(i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the size of second array: ");
    scanf("%d", &n2);

    printf("Enter the elements of second sorted array:\n");
    for(i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    i = 0;

    while(i < n1 && j < n2) {
        if(a[i] < b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        c[k] = a[i];
        i++;
        k++;
    }

    while(j < n2) {
        c[k] = b[j];
        j++;
        k++;
    }

    printf("Merged Sorted Array:\n");

    for(i = 0; i < k; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}