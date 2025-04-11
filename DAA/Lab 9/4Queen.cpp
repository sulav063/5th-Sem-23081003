#include <iostream>

using namespace std;

const int N = 4; // Size of the chessboard (4x4)

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(int board[N][N], int row) {
    if (row >= N) {
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1)) {
                return true;
            }

            board[row][col] = 0; // Backtrack
        }
    }

    return false;
}

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

int main() {
    int board[N][N] = {0};

    if (solveNQueens(board, 0)) {
        printSolution(board);
    } else {
        cout << "No solution exists\n";
    }

    return 0;
}
