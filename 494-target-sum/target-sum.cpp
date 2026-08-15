class Solution {
public:

    int countPartition(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Sum = 0 can always be formed by choosing nothing
        dp[0][0] = 1;

        // First element
        if (nums[0] <= target)
            dp[0][nums[0]] += 1;

        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= target; sum++) {

                // Don't take
                int notTake = dp[i - 1][sum];

                // Take
                int take = 0;
                if (nums[i] <= sum)
                    take = dp[i - 1][sum - nums[i]];

                dp[i][sum] = take + notTake;
            }
        }

        return dp[n - 1][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;

        for (int x : nums)
            totalSum += x;

        // target cannot be greater than total sum
        if (abs(target) > totalSum)
            return 0;

        // (totalSum + target) must be even
        if ((totalSum + target) % 2 != 0)
            return 0;

        int requiredSum = (totalSum + target) / 2;

        return countPartition(nums, requiredSum);
    }
};