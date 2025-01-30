#include <iostream>
using namespace std;

// Global variable to count the number of steps
int steps = 0;

// Function to swap two numbers in the array
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    steps++; // Increment steps for each swap
}

// Partition function using a pseudo-randomly chosen pivot
int RandomPartition(int arr[], int low, int high) {
    // Use a pseudo-random index based on the size of the current subarray
    int randomIndex = low + (high - low) / 2; // Midpoint as a pseudo-random choice

    // Swap the pseudo-random pivot with the last element
    swap(arr[randomIndex], arr[high]);

    // Now proceed with the normal partition logic
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        steps++; // Increment steps for each comparison
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1; // Return the pivot index
}

// Randomized Quick Sort function
void RandomQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = RandomPartition(arr, low, high); // Pseudo-randomized partition

        // Recursively sort the left and right parts
        RandomQuickSort(arr, low, pi - 1);
        RandomQuickSort(arr, pi + 1, high);
    }
}

int main() {
    // Ask the user for the number of elements
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Create an array to hold the elements
    int arr[n];
    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array using pseudo-randomized quick sort
    RandomQuickSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print the total number of steps
    cout << "Total number of steps: " << steps << endl;

    return 0;
}
