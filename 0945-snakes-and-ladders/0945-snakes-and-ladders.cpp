#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flatBoard(n * n + 1, -1);  // 1-based indexing

        // Flatten the 2D board into 1D array
        bool leftToRight = true;
        int idx = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (leftToRight) {
                for (int j = 0; j < n; ++j)
                    flatBoard[idx++] = board[i][j];
            } else {
                for (int j = n - 1; j >= 0; --j)
                    flatBoard[idx++] = board[i][j];
            }
            leftToRight = !leftToRight;
        }

        vector<bool> visited(n * n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;

        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int s = 0; s < size; ++s) {
                int curr = q.front();
                q.pop();

                if (curr == n * n)
                    return moves;

                for (int dice = 1; dice <= 6; ++dice) {
                    int next = curr + dice;
                    if (next > n * n) continue;

                    if (flatBoard[next] != -1)
                        next = flatBoard[next];

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};
