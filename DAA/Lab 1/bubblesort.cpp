#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &comparisons, int &swaps) {
    bool swapped;
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            comparisons++; // Increment comparison count
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++; // Increment swap count
                swapped = true;
            }
        }
        // If no two elements were swapped in the inner loop, the array is already sorted
        if (!swapped)
            break;
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

    int comparisons, swaps;
    bubbleSort(arr, numElements, comparisons, swaps);

    cout << "Sorted array: ";
    for (int i = 0; i < numElements; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Display the number of steps
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of swaps: " << swaps << endl;

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}

