// Write a program to search an element in an Array using dynamic memory
// allocation. Apply different algorithm separately. Show the running time
// complexity w.r.t different input cases(best/average/worst). Finally
// comment that which one is better and why.

#include <stdio.h>
#include <stdlib.h>

// Linear Search Function
int linearSearch(int *arr, int n, int key) {
    int comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) {
            printf("Linear Search Comparisons: %d\n", comparisons);
            return i; // Element found
        }
    }
    printf("Linear Search Comparisons: %d\n", comparisons);
    return -1; // Element not found
}

// Binary Search Function
int binarySearch(int *arr, int left, int right, int key) {
    int comparisons = 0;
    while (left <= right) {
        // comparisons++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            printf("Binary Search Comparisons: %d\n", comparisons);
            return mid; // Element found
        } else if (arr[mid] < key) {
            comparisons++;
            left = mid + 1;
        } else {
            comparisons++;
            right = mid - 1;
        }
    }
    printf("Binary Search Comparisons: %d\n", comparisons);
    return -1; // Element not found
}

// Main Function
int main() {
    int n, key;

    // Input array size
    printf("Enter size of the array: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    int *arr = (int *)malloc(n * sizeof(int));

    // Input array elements
    printf("Enter %d elements (sorted for Binary Search):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input search key
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform Linear Search
    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1)
        printf("Linear Search: Element found at index %d\n", linearResult);
    else
        printf("Linear Search: Element not found\n");

    // Perform Binary Search
    int binaryResult = binarySearch(arr, 0, n - 1, key);
    if (binaryResult != -1)
        printf("Binary Search: Element found at index %d\n", binaryResult);
    else
        printf("Binary Search: Element not found\n");

    // Free allocated memory
    free(arr);

    return 0;
}
