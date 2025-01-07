#include <iostream>
#include <unordered_set>
using namespace std;

const int MAX_NODES = 1000;

int* FindFriendsOfFriendsBFS(int graph[][MAX_NODES], int numNodes, int person) {
    bool visited[MAX_NODES] = {false};
    int* fof = new int[MAX_NODES];
    int fofCount = 0;
    queue<int> q;
    visited[person] = true;
    q.push(person);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < numNodes; ++i) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    for (int i = 0; i < numNodes; ++i) {
        if (!visited[i] && i != person) {
            for (int j = 0; j < numNodes; ++j) {
                if (visited[j] && graph[i][j]) {
                    fof[fofCount++] = i;
                    break;
                }
            }
        }
    }
    fof[fofCount] = -1;
    return fof;
}

void DepthFirstSearch(int graph[][MAX_NODES], bool visited[], int person, unordered_set<int>& fof, int numNodes) {
    visited[person] = true;
    for (int i = 0; i < numNodes; ++i) {
        if (graph[person][i] && !visited[i]) {
            visited[i] = true;
            for (int j = 0; j < numNodes; ++j) {
                if (j != person && graph[i][j]) {
                    fof.insert(j);
                }
            }
            DepthFirstSearch(graph, visited, i, fof, numNodes);
        }
    }
}

int* FindFriendsOfFriendsDFS(int graph[][MAX_NODES], int numNodes, int person) {
    bool visited[MAX_NODES] = {false};
    unordered_set<int> fofSet;
    DepthFirstSearch(graph, visited, person, fofSet, numNodes);
    int* fof = new int[fofSet.size() + 1];
    int index = 0;
    for (int f : fofSet) {
        fof[index++] = f;
    }
    fof[index] = -1;
    return fof;
}

int main() {
    // Example social network graph (adjacency matrix representation)
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };
    int numNodes = 5;
    int person = 0;
    cout << "Using BFS:" << endl;
    int* bfs_fof = FindFriendsOfFriendsBFS(graph, numNodes, person);
    cout << "Friends-of-friends of person " << person << ": ";
    for (int i = 0; bfs_fof[i] != -1; ++i) {
        cout << bfs_fof[i] << " ";
    }
    cout << endl;
    delete[] bfs_fof;
    cout << "Using DFS:" << endl;
    int* dfs_fof = FindFriendsOfFriendsDFS(graph, numNodes, person);
    cout << "Friends-of-friends of person " << person << ": ";
    for (int i = 0; dfs_fof[i] != -1; ++i) {
        cout << dfs_fof[i] << " ";
    }
    cout << endl;
    delete[] dfs_fof;
    return 0;
}
