#include <iostream>
using namespace std;

const int MAX_NODES = 1000;

bool DepthFirstSearch(int graph[][MAX_NODES], bool visited[], bool recursionStack[], int numNodes, int node) {
    visited[node] = true;
    recursionStack[node] = true;
    for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
        if (graph[node][neighbor] == 1) {
            if (!visited[neighbor]) {
                if (DepthFirstSearch(graph, visited, recursionStack, numNodes, neighbor)) {
                    return true;
                }
            } else if (recursionStack[neighbor]) {
                return true;
            }
        }
    }
    recursionStack[node] = false;
    return false;
}

bool HasCycle(int graph[][MAX_NODES], int numNodes) {
    bool visited[MAX_NODES] = {false};
    bool recursionStack[MAX_NODES] = {false};
    for (int i = 0; i < numNodes; ++i) {
        if (!visited[i]) {
            if (DepthFirstSearch(graph, visited, recursionStack, numNodes, i)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int numNodes = 4;
    int graph[MAX_NODES][MAX_NODES] = {0};

    // Example graph
    graph[0][1] = graph[0][2] = graph[1][2] = graph[2][0] = graph[2][3] = graph[3][3] = 1;
    if (HasCycle(graph, numNodes)) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }
    return 0;
}
