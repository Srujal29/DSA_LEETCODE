class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int mod = 1e9 + 7;

        vector<vector<vector<long long >>> dp(
            m, vector<vector<long long >>(n, vector<long long>(2,0))
        );

        dp[0][0][0] = 1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                long long right = dp[i][j][0];
                long long down = dp[i][j][1];

                if(grid[i][j] == 0){

                    if(j + 1 <  n){
                        dp[i][j+1][0] = (dp[i][j+1][0] + right + down) % mod;
                    }

                    if(i + 1 < m){
                         dp[i+1][j][1] = (dp[i+1][j][1] + right + down) % mod;
                    }
                }
                else{
                    if(i + 1 < m){
                        dp[i+1][j][1] = (dp[i+1][j][1] + right) % mod;
                    }

                    if(j + 1< n){
                        dp[i][j+1][0] = (dp[i][j+1][0] + down) % mod;
                    }
                }
            }
        }
        return (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % mod;
    }
};