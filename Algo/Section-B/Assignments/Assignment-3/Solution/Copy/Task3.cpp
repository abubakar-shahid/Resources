#include <iostream>
#include <climits>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

int MinCostPath(int grid[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int dp[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            dp[i][j] = INT_MAX;
        }
    }
    dp[0][0] = grid[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i != 0 || j != 0) {
                dp[i][j] = grid[i][j] + min((i > 0 ? dp[i - 1][j] : INT_MAX), (j > 0 ? dp[i][j - 1] : INT_MAX));
            }
        }
    }
    return dp[rows - 1][cols - 1];
}

int main() {
    // Example grid
    int grid[MAX_ROWS][MAX_COLS] = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    int rows = 3;
    int cols = 3;
    int minCost = MinCostPath(grid, rows, cols);
    cout << "Minimum cost to reach the bottom right cell: " << minCost << endl;
    return 0;
}
