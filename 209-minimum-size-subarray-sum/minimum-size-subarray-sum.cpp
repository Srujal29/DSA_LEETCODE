class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,len = INT_MAX;
        int sum = 0;
        while(r < nums.size()){
            sum += nums[r];

            while(sum >= target){
                len = min(len , r-l+1);
                sum -= nums[l];
                l++;
            }

            r++;
        }
        if(len == INT_MAX)
            return 0;
        return len;
    }
};