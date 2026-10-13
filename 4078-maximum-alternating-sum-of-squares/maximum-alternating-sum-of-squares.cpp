class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq(nums.size());

        for(int i=0;i<nums.size();i++){
            sq[i] = nums[i] * nums[i];
        }

        sort(sq.begin(),sq.end());

        long long sum = 0;
        for(int i=nums.size()/2;i<nums.size();i++){
            sum += sq[i];
        }
        for(int i=0;i<nums.size() / 2;i++){
            sum -= sq[i];
        }

        return sum;
    }
};