#include <iostream>
using namespace std;
int knapsack(int w[], int v[], int cap, int n) {
    if (n == 0 || cap == 0){
        return 0;
    }
    if (w[n-1] > cap){
        return knapsack(w, v, cap, n-1);
    }
    return max(v[n-1] + knapsack(w, v, cap - w[n-1], n-1), knapsack(w, v, cap, n-1));
}

int main() {
    int cap, n;

    // Get the knapsack capacity
    cout << "Enter knapsack capacity: ";
    cin >> cap;

    // Get the number of items
    cout << "Enter number of items: ";
    cin >> n;

    int w[n], v[n];

    // Get the weights of the items
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    // Get the values (profits) of the items
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    // Compute and display the maximum value
    cout << "Maximum value: " << knapsack(w, v, cap, n) << endl;
    
    return 0;
}
