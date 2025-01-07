#include <iostream>
#include <queue>

using namespace std;

const int MAX_CELLS = 100;

struct Cell {
    int position;
    int moves;
};

int minDiceThrows(int board[], int N) {
    bool visited[MAX_CELLS] = {false};
    queue<Cell> q;
    q.push({1, 0});
    visited[1] = true;
    while (!q.empty()) {
        Cell current = q.front();
        q.pop();
        if (current.position == N - 1) {
            return current.moves;
        }
        for (int i = current.position + 1; i <= current.position + 6 && i < N; ++i) {
            if (!visited[i]) {
                Cell next;
                next.moves = current.moves + 1;
                visited[i] = true;
                if (board[i] != -1) {
                    next.position = board[i];
                }
                else {
                    next.position = i;
                }
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    // Example board
    int board[MAX_CELLS] = {-1, -1, 3, 4, -1, 6, -1, -1, -1, -1, -1, -1, -1};
    int N = 13;
    int minThrows = minDiceThrows(board, N);
    if (minThrows != -1) {
        cout << "Minimum number of dice throws required: " << minThrows << endl;
    }
    else {
        cout << "The last cell is not reachable." << endl;
    }
    return 0;
}
