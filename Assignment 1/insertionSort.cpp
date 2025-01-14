#include <stdio.h>
#include <stdlib.h>

// Function to perform Insertion Sort
void insertionSort(int *arr, int n) {
    int comparisons = 0; // Counter for comparisons
    for (int i = 1; i < n; i++) {
        int j = i;

        // Move elements of arr[0..i-1] that are greater than
        while (j >= 1 && arr[j] < arr[j-1]) {
            comparisons++; // Count comparisons in the while loop
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }

    // Print the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Output comparisons and expected time complexity
    printf("Total Comparisons (actual): %d\n", comparisons);
    printf("Time Complexity (expected): O(n^2) for worst case\n");
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

    // Perform Insertion Sort
    insertionSort(arr, n);

    // Free allocated memory
    free(arr);

    return 0;
}
