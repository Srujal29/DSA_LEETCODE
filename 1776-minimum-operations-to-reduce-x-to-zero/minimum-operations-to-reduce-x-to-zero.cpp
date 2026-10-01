class Solution {
public:
    int helper(vector<int>& nums, int target) {
        int l = 0, r = 0;
        int sum = 0;
        int maxlen = 0;

        while (r < nums.size()) {
            sum += nums[r];

            while (sum > target) {
                sum -= nums[l];
                l++;
            }
            if (sum == target) {
                int len = r - l + 1;
                maxlen = max(maxlen, len);
            }
            r++;
        }
        return maxlen;
    }
    int minOperations(vector<int>& nums, int x) {
        // weh have to find ot who stay in the middle so for that total - x will
        // stay in middle  and have to find out longest subarray with that value

        int total = 0;
        for (int i : nums)
            total += i;

        int target = total - x;
        if (target < 0)
            return -1;

        if (target == 0)
            return nums.size();

        int maxlen = helper(nums, target);

        if (maxlen == 0)
            return -1;

        return nums.size() - maxlen;
    }
};