#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to perform optimized Bubble Sort
void bubbleSort(int *arr, int n) {
    int comparisons = 0; // Counter for comparisons
    bool swapped; // Flag to track if any elements were swapped

    // Bubble Sort algorithm with early exit if no swaps in a pass
    for (int i = 0; i < n - 1; i++) {
        swapped = false; // Reset the swapped flag for each pass

        for (int j = 0; j < n - 1 - i; j++) {
            comparisons++; // Count comparisons

            // Swap if the element is greater than the next one
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true; // Mark that a swap happened
            }
        }

        // If no elements were swapped, the array is already sorted
        if (!swapped) {
            break;
        }
    }

    // Print the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Output comparisons, swaps, and time complexity
    printf("Total Comparisons (actual): %d\n", comparisons);
    printf("Time Complexity (expected): O(n^2) in worst/average case, O(n) in best case\n");
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

    // Perform Bubble Sort
    bubbleSort(arr, n);

    // Free allocated memory
    free(arr);

    return 0;
}
