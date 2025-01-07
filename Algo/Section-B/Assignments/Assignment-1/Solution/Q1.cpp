#include <iostream>

using namespace std;

int* parent;
int* rank;

int find(int i) {
    if (parent[i] == i)
        return i;
    parent[i] = find(parent[i]);
    return parent[i];
}

void unionSets(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);

    if (xRoot != yRoot) {
        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
}

bool canPassResolution(int n, int** pairs, int pairsCount) {
    parent = new int[n];
    rank = new int[n];

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    for (int i = 0; i < pairsCount; ++i) {
        int x = pairs[i][0];
        int y = pairs[i][1];
        if (find(x) != find(y))
            unionSets(x, y);
    }

    int* groupCount = new int[n]();
    for (int i = 0; i < n; ++i)
        groupCount[find(i)]++;

    for (int i = 0; i < n; ++i) {
        if (groupCount[i] > n / 2) {
            delete[] parent;
            delete[] rank;
            delete[] groupCount;
            return true;
        }
    }

    delete[] parent;
    delete[] rank;
    delete[] groupCount;
    return false;
}

int main() {
    int n = 5;
    int** pairs = new int*[5]{{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    int pairsCount = 5;

    if (canPassResolution(n, pairs, pairsCount))
        cout << "There exists a resolution that can be passed.\n";
    else
        cout << "No resolution can be passed.\n";

    for (int i = 0; i < pairsCount; ++i)
        delete[] pairs[i];
    delete[] pairs;

    return 0;
}