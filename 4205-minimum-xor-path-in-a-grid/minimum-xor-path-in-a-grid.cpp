class Solution {
public:
    int helper(int i, int j, int xr, vector<vector<int>>& grid,
               vector<vector<vector<int>>>& dp) {
        int m = grid.size(), n = grid[0].size();

        if (i == m - 1 && j == n - 1)
            return xr;

        if (dp[i][j][xr] != -1)
            return dp[i][j][xr];

        int ans = INT_MAX;

        if (j + 1 < n) {
            ans = min(ans, helper(i, j + 1, xr ^ grid[i][j + 1], grid, dp));
        }

        if (i + 1 < m) {
            ans = min(ans, helper(i + 1, j, xr ^ grid[i + 1][j], grid, dp));
        }

        return dp[i][j][xr] = ans;
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(1024, -1)));
        return helper(0, 0, grid[0][0], grid, dp);
    }
};