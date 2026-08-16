class Solution {
public: 
/*
Kadane's Algo
so here we can take maxi and sum =0 just iterate through the array if greter thatn intmin update it and if sum < zero then sum = 0
if gretaer thZn zero then keep it;

*/

    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum =0;
        for(int i=0;i < nums.size();i++){
            sum += nums[i];
            if(sum > maxi) maxi = sum;
            if(sum < 0) sum =0;
        }
        return maxi;
    }
};