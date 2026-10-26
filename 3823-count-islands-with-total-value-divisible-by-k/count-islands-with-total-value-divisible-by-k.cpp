class Solution {
public:
    int m ,n;
    long long dfs(vector<vector<int>> & grid, int r , int c ){

        if(r < 0 || c < 0 || r >= m || c >= n) return 0;

        if(grid[r][c] == 0 ) return 0;
        long long sum = grid[r][c];

        grid[r][c] = 0;

        sum += dfs(grid,r,c+1);
        sum += dfs(grid,r,c-1);
        sum += dfs(grid,r+1,c);
        sum += dfs(grid,r-1,c);

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
         m = grid.size();
         n = grid[0].size();
        int ans = 0;

        for(int i = 0 ; i < m;i++){
            for(int j =0 ;j < n;j++){
                if(grid[i][j] >= 1){
                    long long total = dfs(grid,i,j);

                    if(total % k == 0) ans++; 
                }
            }
        }

        return ans;
    }
};