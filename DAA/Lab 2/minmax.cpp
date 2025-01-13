#include <iostream>
#include <climits> // for INT_MAX and INT_MIN

using namespace std;

// Function to find the minimum and maximum values in an array
void findMinMax(int arr[], int low, int high, int& min, int& max) {
    // If the array has only one element
    if (low == high) {
        if (arr[low] < min) min = arr[low];
        if (arr[low] > max) max = arr[low];
        return;
    }

    // If the array has two elements, compare them directly
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            if (arr[low] < min) min = arr[low];
            if (arr[high] > max) max = arr[high];
        } else {
            if (arr[high] < min) min = arr[high];
            if (arr[low] > max) max = arr[low];
        }
        return;
    }

    // If the array has more than two elements, divide it into two parts
    int mid = low + (high - low) / 2;

    // Recursively find the min and max in the left and right halves
    findMinMax(arr, low, mid, min, max);
    findMinMax(arr, mid + 1, high, min, max);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize min and max with extreme values
    int min = INT_MAX;
    int max = INT_MIN;

    // Find the min and max using the algorithm
    findMinMax(arr, 0, n - 1, min, max);

    // Output the results
    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    return 0;
}

