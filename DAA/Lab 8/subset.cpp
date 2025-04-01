#include <iostream>
using namespace std;

void PrintSubsetSum(int i, int n, int set[], int targetSum, int subset[], int subsetSize) {
    // If targetSum is zero, print the subset
    if (targetSum == 0) {
        cout << "[ ";
        for (int j = 0; j < subsetSize; j++) {
            cout << subset[j] << " ";
        }
        cout << "]\n";
        return;
    }

    if (i == n) {
        return;
    }

    // Not considering the current element
    PrintSubsetSum(i + 1, n, set, targetSum, subset, subsetSize);

    // Consider the current element if it is less than or equal to targetSum
    if (set[i] <= targetSum) {
        subset[subsetSize] = set[i];  // Add current element to subset
        // Recur with the updated targetSum and the updated subset
        PrintSubsetSum(i + 1, n, set, targetSum - set[i], subset, subsetSize + 1);
    }
}

int main() {
    int n, sum;

    // Ask the user for the number of elements in the set
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    int set[n]; // Create an array of size 'n'

    // Ask the user to enter the elements of the set
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    // Ask the user for the target sum
    cout << "Enter the target sum: ";
    cin >> sum;

    int subset[n]; // Array to store the current subset

    cout << "Subsets with sum " << sum << ":\n";
    PrintSubsetSum(0, n, set, sum, subset, 0);

    return 0;
}

