#include <iostream>
#include <queue>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void DFS(int grid[MAX_ROWS][MAX_COLS], int rows, int cols, int row, int col) {
    grid[row][col] = 0;
    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    for (int i = 0; i < 8; ++i) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
            DFS(grid, rows, cols, newRow, newCol);
        }
    }
}

int CountIslands(int grid[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int islands = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                DFS(grid, rows, cols, i, j);
                islands++;
            }
        }
    }
    return islands;
}

int main() {
    // Example grid
    int grid[MAX_ROWS][MAX_COLS] = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
    int rows = 5;
    int cols = 5;
    int islands = CountIslands(grid, rows, cols);
    cout << "Number of islands: " << islands << endl;
    return 0;
}
