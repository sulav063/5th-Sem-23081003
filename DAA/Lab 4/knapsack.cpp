#include <iostream>
using namespace std;

// Structure to store weight, value, and ratio
struct Item {
    int weight, value;
    float ratio;
};

// Function to manually sort items based on value/weight ratio (Bubble Sort)
void sortItems(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap(items[j], items[j + 1]);
            }
        }
    }
}

// Function to perform the Fractional Knapsack algorithm
float GreedyfracKnapsack(Item items[], int n, int W) {
    sortItems(items, n); // Sort items by decreasing ratio

    float maxProfit = 0.0;
    int tempW = W;

    for (int i = 0; i < n; i++) {
        if (tempW >= items[i].weight) {
            // Take full item
            tempW -= items[i].weight;
            maxProfit += items[i].value;
        } else {
            // Take fraction of item
            maxProfit += (float)tempW / items[i].weight * items[i].value;
            break; // Stop since knapsack is full
        }
    }
    return maxProfit;
}

// Driver Code
int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter maximum knapsack capacity: ";
    cin >> W;

    Item items[100]; // Static array (max 100 items)

    cout << "Enter weight and value of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    float maxProfit = GreedyfracKnapsack(items, n, W);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
