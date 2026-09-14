class Solution {
public:
    int helper(vector<int> & nums, int one_day){

        int sum = 0;
        int days = 1;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum > one_day){
                days++;
                sum = nums[i];

            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = 1;
        int high = 0;
        for(int x : weights){
            low = max (low, x);
            high += x;
        }

        while(low <= high){
            int mid = (low + high) / 2;
            int nofDays = helper(weights, mid);

            if(nofDays <= days){
                high = mid -1;
            }else low = mid + 1;
        }

        return low;
    }
};