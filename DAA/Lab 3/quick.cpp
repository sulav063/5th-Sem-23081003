#include <iostream>
using namespace std;

// Global variable to count the number of steps
int steps = 0;

// Function to swap two integers
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    steps++; // Count the swap as a step
}

// Partition function to rearrange the elements around the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j < high; ++j) {
        steps++; // Count the comparison as a step
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]); // Count the swap
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in the correct position
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the index of the pivot
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // Input
    cout << "Enter the number of elements: ";
    int numElements;
    cin >> numElements;

    int arr[numElements];

    cout << "Enter the elements:\n";
    for (int i = 0; i < numElements; ++i) {
        cin >> arr[i];
    }

    // Sorting
    quickSort(arr, 0, numElements - 1);

    // Output
    cout << "Sorted array: ";
    for (int i = 0; i < numElements; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print the total number of steps
    cout << "Total number of steps: " << steps << endl;

    return 0;
}

