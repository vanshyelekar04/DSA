class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        int alreadyset = image[sr][sc];

        if (alreadyset == color)
            return image;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1; // mark visited
        image[sr][sc] = color;

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    image[nrow][ncol] == alreadyset && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
        return image;
    }
};