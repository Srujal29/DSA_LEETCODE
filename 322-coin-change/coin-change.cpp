class Solution {
public:
/*
    peoblem is to fig out min coins change
    f(ind, target) -> exprssion  -> min of all
    
    base case :
    if( ind = 0){
        if(target % arr[i] == 0) return target / a[i];
        else return INT_MAX;
    }
    nottake = 0 + f(ind-1, T)
    take = int max

    unlimited coins le sakta hai toh take me same coince use kar skate hai after same time the if conditin nfails and we can directly  go tot nontake and ind-1

    if(target>=arr[idx]) take = 1 + f( idx,tar - arr[idx]);

    min(take , nottake);

*/  
    int solve(int idx , vector<int> &coins, int amount,vector<vector<int>> &dp){
        
        if(idx == 0){
            if(amount % coins[idx] == 0) return amount/coins[idx];
             return 1e9;
        }

        if(dp[idx][amount] != -1) return dp[idx][amount];
        int nottake = 0 + solve(idx - 1, coins, amount,dp);
        int take = 1e9;
        if(amount >= coins[idx]){
            take = 1 + solve(idx,coins, amount - coins[idx],dp);
        }

        return dp[idx][amount] =  min(take,nottake);

    }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int> (amount+1 , -1));
    //     int ans = solve(n-1 , coins, amount,dp);

    //     if(ans >= 1e9){
    //         ans = -1;
    //     }
    //     return ans;
    // }

    //tabulation
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1 , -1));
        for(int t = 0; t <= amount;t++){
            if(t % coins[0] == 0){
                dp[0][t] = t / coins[0]; 
            }else {
                 dp[0][t] = 1e9; 
            }
        }

        for(int i=1; i < n;i++){
            for(int tar = 0; tar <= amount;tar++){
                int nottake = 0 + dp[i-1][tar];
                int take = 1e9;
                if(tar >= coins[i]){
                    take = 1 + dp[i][tar-coins[i]];
                }
                 dp[i][tar] =  min(take,nottake);
            }
        }

       int ans = dp[n-1][amount];

        if(ans >= 1e9)
            return -1;

        return ans;
    }
};