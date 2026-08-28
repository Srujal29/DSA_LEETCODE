class Solution {
public:
int f(int idx, int buy, vector<int> &prices){
    if(idx == prices.size()) return 0;

    long profit = 0;
    if(buy){
        profit = max(-prices[idx] + f(idx + 1, 0, prices), f(idx+1, 1,prices));
    }
    else {
         profit = max(prices[idx] + f(idx + 1, 1, prices), f(idx+1, 0,prices));
    }
    return profit;
}
    int maxProfit(vector<int>& prices) {
    //   return f(0, 1, prices);  
    int n = prices.size();
    vector<vector<long>> dp(n+1, vector<long> (2,0));
    dp[n][0] = dp[n][1] = 0;
    for(int idx = n-1;idx>=0;idx--){
        for(int buy = 0;buy <=1;buy++){
            long profit = 0;
            if(buy){
                profit = max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
            }
            else {
                profit = max(prices[idx] + dp[idx+1][1], dp[idx+1][0]);
            }
            dp[idx][buy] = profit;
        }
    }
    return dp[0][1];

    }
};