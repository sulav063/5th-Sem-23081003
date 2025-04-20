#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int board[10]; // Supports N up to 10
int N;

// Check if it's safe to place a queen
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || (board[i] - i) == (col - row) || (board[i] + i) == (col + row))
            return false;
    }
    return true;
}

// Simple random shuffle for columns
void shuffle(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int r = rand() % size;
        int temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
    }
}

// Backtracking to place queens
bool solve(int row) {
    if (row == N) return true;

    int cols[10];
    for (int i = 0; i < N; i++) cols[i] = i;
    shuffle(cols, N); // Random order

    for (int i = 0; i < N; i++) {
        int col = cols[i];
        if (isSafe(row, col)) {
            board[row] = col;
            if (solve(row + 1)) return true;
        }
    }
    return false;
}

// Main function
int main() {
    srand(time(0)); // Seed for randomness

    cout << "Enter N (4 to 10): ";
    cin >> N;

    if (N < 4 || N > 10) {
        cout << "N must be between 4 and 10.\n";
        return 0;
    }

    if (solve(0)) {
        cout << "\nRandom N-Queen Solution:\n\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j) cout << "Q ";
                else cout << ". ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found.\n";
    }

    return 0;
}

