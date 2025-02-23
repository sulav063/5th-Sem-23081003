#include <iostream>
#include <climits> // For INT_MAX and INT_MIN

using namespace std;

// Global counter for the number of steps
int steps = 0;

// Function to find the minimum and maximum values in an array
void findMinMax(int arr[], int low, int high, int& min, int& max) {
    // If the array has only one element
    if (low == high) {
        steps++; // Increment step for comparison
        if (arr[low] < min) {
            min = arr[low];
            steps++; // Increment step for assignment
        }
        steps++; // Increment step for comparison
        if (arr[low] > max) {
            max = arr[low];
            steps++; // Increment step for assignment
        }
        return;
    }

    // If the array has two elements, compare them directly
    if (high == low + 1) {
        steps++; // Increment step for comparison
        if (arr[low] < arr[high]) {
            steps++; // Increment step for comparison
            if (arr[low] < min) {
                min = arr[low];
                steps++; // Increment step for assignment
            }
            steps++; // Increment step for comparison
            if (arr[high] > max) {
                max = arr[high];
                steps++; // Increment step for assignment
            }
        } else {
            steps++; // Increment step for comparison
            if (arr[high] < min) {
                min = arr[high];
                steps++; // Increment step for assignment
            }
            steps++; // Increment step for comparison
            if (arr[low] > max) {
                max = arr[low];
                steps++; // Increment step for assignment
            }
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
    cout << "Number of steps: " << steps << endl; // Output the number of steps

    return 0;
}
