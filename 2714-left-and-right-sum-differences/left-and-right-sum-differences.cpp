class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for(int x : nums){
            total += x;
        }

        vector<int> ans(n);
        int leftsum = 0;

        for(int i =0; i< n;i++){

           int rightsum = total - leftsum - nums[i];
           ans[i] = abs(leftsum - rightsum);
           leftsum += nums[i];
        }
        return ans;
    }
};