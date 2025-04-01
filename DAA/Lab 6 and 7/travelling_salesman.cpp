#include <iostream>

using namespace std;

#define INF 404  // Large value representing infinity
#define MAX 10   // Maximum number of cities

int N;              // Number of cities
int dist[MAX][MAX]; // Distance matrix
bool visited[MAX];  // Array to keep track of visited cities

// Recursive TSP function
int tsp(int pos, int count, int cost) {
    if (count == N) {
        return cost + dist[pos][0]; // Return to the starting city
    }

    int ans = INF;
    for (int city = 0; city < N; city++) {
        if (!visited[city]) {
            visited[city] = true;
            ans = min(ans, tsp(city, count + 1, cost + dist[pos][city]));
            visited[city] = false; // Backtrack
        }
    }
    return ans;
}

int main() {
    cout << "Enter number of cities: ";
    cin >> N;

    cout << "Enter distance matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> dist[i][j];
        }
    }

    // Mark all cities as unvisited
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }

    visited[0] = true; // Start from city 0
    int result = tsp(0, 1, 0); // Start at city 0 with cost 0

    cout << "Minimum cost of TSP: " << result << endl;

    return 0;
}

