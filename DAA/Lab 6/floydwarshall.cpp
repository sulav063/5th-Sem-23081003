#include <iostream>

using namespace std;

#define INF 404  // A large value to represent infinity
#define MAX 100    // Maximum number of vertices

void floydWarshall(int W[MAX][MAX], int D[MAX][MAX], int n) {
    // Step 1: Copy the input weight matrix W to distance matrix D
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            D[i][j] = W[i][j]; // Original D° matrix
        }
    }

    // Step 2: Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (D[i][j] > D[i][k] + D[k][j]) { // Relaxation step
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    // Step 3: Print the shortest distance matrix
    cout << "The shortest distances between every pair of vertices:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (D[i][j] == INF)
                cout << "INF ";
            else
                cout << D[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    int W[MAX][MAX], D[MAX][MAX];

    cout << "Enter the adjacency matrix (use " << INF << " for infinity):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> W[i][j];
        }
    }

    floydWarshall(W, D, n);

    return 0;
}

