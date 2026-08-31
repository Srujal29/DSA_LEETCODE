class Solution {
public:
    int f(int idx, int prev_idx, vector<int>&nums, vector<vector<int>> &dp){

        if(idx == nums.size()) return 0;
        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx + 1];
        int nottake = f(idx + 1, prev_idx, nums,dp);
        int take = 0;
        if(prev_idx == -1 || nums[prev_idx] < nums[idx]){
            take = 1 + f(idx + 1, idx, nums,dp);
        }

        return dp[idx][prev_idx+1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
     return f(0, -1,nums,dp);   
    }
};