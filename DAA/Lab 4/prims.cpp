#include <iostream>
#define INF 9999999  // Define a large number representing infinity
#define MAX 100      // Define the maximum number of vertices

int G[MAX][MAX];  // Adjacency matrix to represent the graph
int selected[MAX]; // Array to keep track of which vertices have been selected

using namespace std;

// Function to implement Prim's algorithm for finding the Minimum Spanning Tree (MST)
void primsAlgorithm(int V) {
    int no_edge = 0;  // Initialize the number of edges in the MST
    selected[0] = 1;  // Start from vertex 0 (mark it as selected)

    cout << "Edge : Weight\n";  // Output header for the edges and their weights
    
    // Loop until we have selected V - 1 edges for the MST
    while (no_edge < V - 1) {
        int min = INF, x = 0, y = 0;  // Initialize variables to store minimum weight and edge

        // Loop through all vertices to find the edge with the minimum weight
        for (int i = 0; i < V; i++) {
            if (selected[i]) {  // If vertex i is selected
                for (int j = 0; j < V; j++) {
                    // Check if vertex j is not selected and if there is an edge between i and j
                    if (selected[j] == 0 && G[i][j] != 0 && G[i][j] < min) {
                        min = G[i][j];  // Update the minimum weight
                        x = i;           // Set vertex x to the current vertex i
                        y = j;           // Set vertex y to the adjacent vertex j
                    }
                }
            }
        }

        // Output the selected edge and its weight
        cout << x << " - " << y << " : " << G[x][y] << endl;
        
        selected[y] = 1;  // Mark vertex y as selected
        no_edge++;  // Increment the number of edges selected
    }
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;  // Input the number of vertices

    // Input the adjacency matrix representing the graph
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> G[i][j];  // Input each edge's weight
        }
        selected[i] = 0;  // Initialize all vertices as not selected
    }

    // Call the Prim's algorithm function to find the MST
    primsAlgorithm(V);

    return 0;
}
