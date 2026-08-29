class Solution {
public:
    int f(int ind, int transno, vector<int>& prices, int n, int k, vector<vector<int>> &dp){
        if(ind == n  || transno == 2*k) return 0;
        if(dp[ind][transno] != -1) return dp[ind][transno];
        if(transno % 2 == 0){ // buy
            return dp[ind][transno] = max(-prices[ind] + f(ind+1,transno+1, prices,n, k,dp),
                        0 + f(ind + 1, transno, prices, n ,k,dp)
            );
        }
        return dp[ind][transno] =  max(prices[ind] + f(ind+1,transno+1, prices,n,k,dp),
                    0 + f(ind+1,transno, prices,n,k,dp)
        );
    }
   

    int maxProfit(int k, vector<int>& prices) {
       int n  = prices.size();
       vector<vector<int>> dp(n, vector<int>(2*k,-1));
       return f(0,0,prices,n,k,dp);
    }
};