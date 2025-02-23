#include <iostream>
using namespace std;

// Function to solve 0/1 Knapsack using Dynamic Programming
int dynamicknapsack(int capacity, int weights[], int values[], int n) {
    int *dp = new int[capacity + 1]();  // 1D array for space optimization, initialized to 0

    // Fill the DP table in reverse order to avoid reusing the same item
    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }

    int maxProfit = dp[capacity]; // Maximum value that can be obtained
    delete[] dp;  // Free allocated memory
    return maxProfit;
}

int main() {
    int n, capacity;
    
    // User input: number of items and maximum capacity
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int *weights = new int[n];  // Dynamic array for weights
    int *values = new int[n];   // Dynamic array for values0
    
    // Input weights and values of items
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> weights[i];
    
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> values[i];

    // Solve the problem
    int maxProfit = dynamicknapsack(capacity, weights, values, n);
    cout << "Maximum value in Knapsack = " << maxProfit << endl;

    return 0;
}
