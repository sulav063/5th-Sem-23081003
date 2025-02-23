#include <iostream>
#define MAX 100

using namespace std;

struct Edge {
    int u, v, w;
};

class Kruskal {
private:
    int n, e;
    Edge edges[MAX], spanTree[MAX];
    int parent[MAX];

public:
    Kruskal(int vertices, int edges) : n(vertices), e(edges) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    void addEdge(int index, int u, int v, int w) {
        edges[index] = {u, v, w};
    }

    int find(int vertex) {
        if (parent[vertex] != vertex)
            parent[vertex] = find(parent[vertex]);
        return parent[vertex];
    }

    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        parent[rootV] = rootU;
    }

    void sortEdges() {
        for (int i = 0; i < e - 1; i++) {
            for (int j = 0; j < e - i - 1; j++) {
                if (edges[j].w > edges[j + 1].w) {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }
    }

    void kruskalAlgorithm() {
        sortEdges();
        int count = 0, totalCost = 0;
        cout << "Minimum Spanning Tree:\n";
        
        for (int i = 0; i < e; i++) {
            if (find(edges[i].u) != find(edges[i].v)) {
                cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << endl;
                totalCost += edges[i].w;
                unionSet(edges[i].u, edges[i].v);
                count++;
                if (count == n - 1)
                    break;
            }
        }
        cout << "Total Cost: " << totalCost << endl;
    }
};

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    Kruskal kruskal(n, e);
    
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        kruskal.addEdge(i, u, v, w);
    }

    kruskal.kruskalAlgorithm();
    
    return 0;
}