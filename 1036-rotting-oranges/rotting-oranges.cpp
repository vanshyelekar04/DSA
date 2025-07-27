class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // define vis-arrray[n,m] and queue{{row, col},time}
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 2;       // mark visited and rotten
                    q.push({{i, j}, 0}); // initial time is 0
                } else {
                    vis[i][j] = 0; // mark not visited and zero
                }
            }
        }

        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        // BFS
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i]; // traversing to neighbour row
                int ncol = c + dcol[i]; // traversing to neighbour col
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        // check for any fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};