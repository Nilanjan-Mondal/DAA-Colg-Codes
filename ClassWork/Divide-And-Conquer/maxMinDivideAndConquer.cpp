#include <stdio.h>

int count  = 0;

// Recursive function to find the maximum and minimum in the array
void findMaxMin(int arr[], int start, int end, int *maxVal, int *minVal) {

// TC = 3n/2 - 2 = O(n) for divide and conquer
// TC = 2n - 2 = O(n) for brute force

    // Base case: Only one element
    if (start == end) {
        *maxVal = arr[start];
        *minVal = arr[start];
        return;
    }

    // Base case: Two elements
    else if (start + 1 == end) {
        if (arr[start] > arr[end]) {
            *maxVal = arr[start];
            *minVal = arr[end];
        } else {
            *maxVal = arr[end];
            *minVal = arr[start];
        }
        return;
    }

    else {
        // comparisons need to be done only when recursion calles are made
        count++;  //  kotobar array ta divide korbe
        // Divide the array into two halves
        int mid = (start + end) / 2;

        // Variables to store results of left and right halves
        int leftMax, leftMin, rightMax, rightMin;

        // Recursively find max and min for left half
        findMaxMin(arr, start, mid, &leftMax, &leftMin);

        // Recursively find max and min for right half
        findMaxMin(arr, mid + 1, end, &rightMax, &rightMin);

        // Combine results
        *maxVal = (leftMax > rightMax) ? leftMax : rightMax;
        *minVal = (leftMin < rightMin) ? leftMin : rightMin;
    }

    
}

int main() {
    // Input array
    int arr[] = {12, 3, 5, 7, 19, -4, 8, 4, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Variables to store the result
    int maxVal, minVal;

    // Call the recursive function
    findMaxMin(arr, 0, size - 1, &maxVal, &minVal);

    // Output the results
    printf("Maximum: %d\n", maxVal);
    printf("Minimum: %d\n", minVal);
    printf("Count: %d\n", count);

    return 0;
}
