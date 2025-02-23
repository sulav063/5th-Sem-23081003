#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int &comparisons, int &shifts) {
    comparisons = 0;
    shifts = 0;

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Count the initial placement of the key
        shifts++;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            comparisons++; // Increment for the comparison
            arr[j + 1] = arr[j];
            shifts++; // Increment for the shift
            j = j - 1;
        }
        comparisons++; // Increment for the failed comparison in the while loop

        arr[j + 1] = key; // Place the key
    }
}

int main() {
    cout << "Enter the number of elements: ";
    int numElements;
    cin >> numElements;

    int *arr = new int[numElements];

    cout << "Enter the elements:\n";
    for (int i = 0; i < numElements; ++i) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < numElements; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int comparisons, shifts;
    insertionSort(arr, numElements, comparisons, shifts);

    cout << "Sorted array: ";
    for (int i = 0; i < numElements; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Display the number of steps
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of shifts: " << shifts << endl;

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}

