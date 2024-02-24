#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100
int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}
void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}
void primMST(int V) {
    int graph[MAX_VERTICES][MAX_VERTICES];
    if (V <= 0 || V > MAX_VERTICES) {
        printf("Invalid number of vertices. Please enter a value between 1 and %d.\n", MAX_VERTICES);
        return;
    }
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            printf("Enter the weight of edge (%d, %d): ", i, j);
            if (scanf("%d", &graph[i][j]) != 1 || graph[i][j] < 0) {
                fprintf(stderr, "Invalid input: Please enter a non-negative integer for weight.\n");
                return;
            }
            graph[j][i] = graph[i][j]; 
        }
    }

    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;  
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);

        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, V);
}

int main() {
    int V;

    printf("Enter the number of vertices (maximum: %d): ", MAX_VERTICES);
    if (scanf("%d", &V) != 1) {
        fprintf(stderr, "Invalid input: Please enter a valid integer.\n");
        return 1;
    }

    primMST(V);

    return 0;
}

