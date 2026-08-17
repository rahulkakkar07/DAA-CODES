import random
import time
import matplotlib.pyplot as plt

# Number of elements
N = 1000

# Generate 1000 random numbers
original = [random.randint(1, 10000) for _ in range(N)]

# ------------------------------------------------
# SEARCHING ALGORITHMS
# ------------------------------------------------

# Linear Search
def linear_search(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i
    return -1


# Binary Search
def binary_search(arr, key):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1

    return -1


# ------------------------------------------------
# SORTING ALGORITHMS
# ------------------------------------------------

# Bubble Sort
def bubble_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        for j in range(n - i - 1):

            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


# Insertion Sort
def insertion_sort(arr):
    for i in range(1, len(arr)):

        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key


# Quick Sort
def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[-1]

    left = []
    right = []

    for x in arr[:-1]:
        if x <= pivot:
            left.append(x)
        else:
            right.append(x)

    return quick_sort(left) + [pivot] + quick_sort(right)


# Merge Sort
def merge_sort(arr):

    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2

    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    result = []

    i = 0
    j = 0

    while i < len(left) and j < len(right):

        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])

    return result


# ------------------------------------------------
# SEARCH TIME COMPARISON
# ------------------------------------------------

key = original[500]

# Linear Search
start = time.perf_counter()
linear_search(original, key)
linear_time = time.perf_counter() - start


# Binary Search needs sorted array
sorted_array = sorted(original)

start = time.perf_counter()
binary_search(sorted_array, key)
binary_time = time.perf_counter() - start


print("SEARCHING")
print("-----------------------")
print("Linear Search :", linear_time)
print("Binary Search :", binary_time)


# ------------------------------------------------
# SORTING TIME COMPARISON
# ------------------------------------------------

# Bubble Sort
arr = original.copy()

start = time.perf_counter()
bubble_sort(arr)
bubble_time = time.perf_counter() - start


# Insertion Sort
arr = original.copy()

start = time.perf_counter()
insertion_sort(arr)
insertion_time = time.perf_counter() - start


# Quick Sort
arr = original.copy()

start = time.perf_counter()
quick_sort(arr)
quick_time = time.perf_counter() - start


# Merge Sort
arr = original.copy()

start = time.perf_counter()
merge_sort(arr)
merge_time = time.perf_counter() - start


print("\nSORTING")
print("-----------------------")
print("Bubble Sort    :", bubble_time)
print("Insertion Sort :", insertion_time)
print("Quick Sort     :", quick_time)
print("Merge Sort     :", merge_time)


# ------------------------------------------------
# GRAPH 1 - SEARCHING
# ------------------------------------------------

search_names = ["Linear Search", "Binary Search"]
search_times = [linear_time, binary_time]

plt.figure(figsize=(8, 5))

plt.bar(search_names, search_times)

plt.xlabel("Searching Algorithm")
plt.ylabel("Time (seconds)")
plt.title("Linear Search vs Binary Search")

plt.show()


# ------------------------------------------------
# GRAPH 2 - SORTING
# ------------------------------------------------

sort_names = [
    "Bubble Sort",
    "Insertion Sort",
    "Quick Sort",
    "Merge Sort"
]

sort_times = [
    bubble_time,
    insertion_time,
    quick_time,
    merge_time
]

plt.figure(figsize=(9, 5))

plt.bar(sort_names, sort_times)

plt.xlabel("Sorting Algorithm")
plt.ylabel("Time (seconds)")
plt.title("Sorting Algorithm Comparison")

plt.show()