class Solution {
public:
    int solve(int i, int j,string &s, string &t){

        if(j == 0) return 1;
        if(i == 0) return 0; 

        if(s[i-1] == t[j-1]) return solve(i-1,j-1,s,t) + solve(i-1,j,s,t);
        else return solve(i-1,j,s,t);
    }
    int numDistinct(string s, string t) {
        // return solve(s.size(),t.size(),s,t);
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n +1 , vector<double> (m+1,0));
        for(int i=0;i<=n;i++) dp[i][0] = 1;
     

        for(int i=1;i <=n;i++){
            for(int j = 1;j<=m;j++){

                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};