#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define SEARCH_REPEAT 100000
#define SORT_REPEAT 20


// ---------------- LINEAR SEARCH ----------------
int linearSearch(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }

    return -1;
}


// ---------------- BINARY SEARCH ----------------
int binarySearch(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}


// ---------------- BUBBLE SORT ----------------
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];

                a[j] = a[j + 1];

                a[j + 1] = temp;
            }
        }
    }
}


// ---------------- INSERTION SORT ----------------
void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];

        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];

            j--;
        }

        a[j + 1] = key;
    }
}


// ---------------- QUICK SORT ----------------
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[high];

        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (a[j] <= pivot)
            {
                i++;

                int temp = a[i];

                a[i] = a[j];

                a[j] = temp;
            }
        }

        int temp = a[i + 1];

        a[i + 1] = a[high];

        a[high] = temp;

        int p = i + 1;

        quickSort(a, low, p - 1);

        quickSort(a, p + 1, high);
    }
}


// ---------------- MERGE FUNCTION ----------------
void merge(int a[], int low, int mid, int high)
{
    int temp[N];

    int i = low;

    int j = mid + 1;

    int k = low;


    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];

            i++;
        }
        else
        {
            temp[k] = a[j];

            j++;
        }

        k++;
    }


    while (i <= mid)
    {
        temp[k] = a[i];

        i++;

        k++;
    }


    while (j <= high)
    {
        temp[k] = a[j];

        j++;

        k++;
    }


    for (i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}


// ---------------- MERGE SORT ----------------
void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);

        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}


// =================================================
//                    MAIN FUNCTION
// =================================================

int main()
{
    int original[N];
    int a[N];

    clock_t start, end;

    double linearTime;
    double binaryTime;

    double bubbleTime;
    double insertionTime;
    double quickTime;
    double mergeTime;

    int key;

    volatile int result;


    // ---------------------------------------------
    // GENERATE 1000 RANDOM NUMBERS
    // ---------------------------------------------

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        original[i] = rand() % 10000;
    }

    printf("1000 random numbers generated.\n\n");


    // ---------------------------------------------
    // PREPARE ARRAY FOR BINARY SEARCH
    // ---------------------------------------------

    for (int i = 0; i < N; i++)
    {
        a[i] = original[i];
    }

    // Sort the array because binary search needs
    // a sorted array.

    quickSort(a, 0, N - 1);


    // Choose the last element.
    // This makes Linear Search do more comparisons.

    key = a[N - 1];


    // ---------------------------------------------
    // LINEAR SEARCH
    // ---------------------------------------------

    start = clock();

    for (int i = 0; i < SEARCH_REPEAT; i++)
    {
        result = linearSearch(a, N, key);
    }

    end = clock();

    linearTime =
        ((double)(end - start)) / CLOCKS_PER_SEC;


    // ---------------------------------------------
    // BINARY SEARCH
    // ---------------------------------------------

    start = clock();

    for (int i = 0; i < SEARCH_REPEAT; i++)
    {
        result = binarySearch(a, N, key);
    }

    end = clock();

    binaryTime =
        ((double)(end - start)) / CLOCKS_PER_SEC;


    // ---------------------------------------------
    // BUBBLE SORT
    // ---------------------------------------------

    start = clock();

    for (int repeat = 0; repeat < SORT_REPEAT; repeat++)
    {
        // Copy original random array
        for (int i = 0; i < N; i++)
        {
            a[i] = original[i];
        }

        bubbleSort(a, N);
    }

    end = clock();

    bubbleTime =
        ((double)(end - start)) / CLOCKS_PER_SEC;


    // ---------------------------------------------
    // INSERTION SORT
    // ---------------------------------------------

    start = clock();

    for (int repeat = 0; repeat < SORT_REPEAT; repeat++)
    {
        // Copy original random array
        for (int i = 0; i < N; i++)
        {
            a[i] = original[i];
        }

        insertionSort(a, N);
    }

    end = clock();

    insertionTime =
        ((double)(end - start)) / CLOCKS_PER_SEC;


    // ---------------------------------------------
    // QUICK SORT
    // ---------------------------------------------

    start = clock();

    for (int repeat = 0; repeat < SORT_REPEAT; repeat++)
    {
        // Copy original random array
        for (int i = 0; i < N; i++)
        {
            a[i] = original[i];
        }

        quickSort(a, 0, N - 1);
    }

    end = clock();

    quickTime =
        ((double)(end - start)) / CLOCKS_PER_SEC;


    // ---------------------------------------------
    // MERGE SORT
    // ---------------------------------------------

    start = clock();

    for (int repeat = 0; repeat < SORT_REPEAT; repeat++)
    {
        // Copy original random array
        for (int i = 0; i < N; i++)
        {
            a[i] = original[i];
        }

        mergeSort(a, 0, N - 1);
    }

    end = clock();

    mergeTime =
        ((double)(end - start)) / CLOCKS_PER_SEC;


    // ---------------------------------------------
    // DISPLAY RESULTS
    // ---------------------------------------------

    printf("SEARCHING ALGORITHMS\n");
    printf("-----------------------------\n");

    printf("Linear Search Time = %.6f seconds\n",
           linearTime);

    printf("Binary Search Time = %.6f seconds\n",
           binaryTime);


    printf("\nSORTING ALGORITHMS\n");
    printf("-----------------------------\n");

    printf("Bubble Sort Time    = %.6f seconds\n",
           bubbleTime);

    printf("Insertion Sort Time = %.6f seconds\n",
           insertionTime);

    printf("Quick Sort Time     = %.6f seconds\n",
           quickTime);

    printf("Merge Sort Time     = %.6f seconds\n",
           mergeTime);


    return 0;
}