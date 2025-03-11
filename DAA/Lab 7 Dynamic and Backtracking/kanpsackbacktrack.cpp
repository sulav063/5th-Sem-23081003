#include <iostream>
using namespace std;

// Function to solve the 0/1 Knapsack problem using backtracking
int knapsackBacktracking(int weights[], int values[], int capacity, int n) {
    // Base case: if no items left or capacity is 0
    if (n == 0 || capacity == 0)
        return 0;

    // If the weight of the current item is more than the capacity, skip it
    if (weights[n-1] > capacity)
        return knapsackBacktracking(weights, values, capacity, n-1);

    // Return the maximum of two cases:
    // 1. Include the current item and reduce capacity
    // 2. Exclude the current item
    int include_item = values[n-1] + knapsackBacktracking(weights, values, capacity - weights[n-1], n-1);
    int exclude_item = knapsackBacktracking(weights, values, capacity, n-1);

    // Return the maximum value between including and excluding the current item
    if (include_item > exclude_item)
        return include_item;
    else
        return exclude_item;
}

int main() {
    int n, capacity;

    // Ask user for the number of items
    cout << "Enter the number of items: ";
    cin >> n;

    // Arrays to store weights and values of items
    int weights[n], values[n];

    // Ask user for weights and values of each item
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // Ask user for the capacity of the knapsack
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    // Call the knapsack function and print the result
    int max_value = knapsackBacktracking(weights, values, capacity, n);
    cout << "Maximum value achievable: " << max_value << endl;

    return 0;
}

