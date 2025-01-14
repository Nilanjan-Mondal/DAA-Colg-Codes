#include <stdio.h>
#include <iostream>
#include <stdlib.h>

// Function to perform Selection Sort
void selectionSort(int *arr, int n) {
    int comparisons = 0; // Counter for comparisons

    for (int i = 0; i < n - 1; i++) {
        int min = INT_MAX;
        int mindx = -1;
        // Find the minimum element in the remaining unsorted portion
        for (int j = i; j < n; j++) {
            comparisons++; // Count comparisons
            if (arr[j] < min) {
                min = arr[j];
                mindx = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[mindx];
        arr[mindx] = arr[i];
        arr[i] = temp;
    }

    // Print the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Output comparisons and time complexity
    printf("Total Comparisons (actual): %d\n", comparisons);
    printf("Time Complexity (expected): O(n^2) for worst/average case\n");
}

// Main function
int main() {
    int n;

    // Input array size
    printf("Enter size of the array: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    int *arr = (int *)malloc(n * sizeof(int));

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display original array
    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform Selection Sort
    selectionSort(arr, n);

    // Free allocated memory
    free(arr);

    return 0;
}
