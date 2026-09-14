class Solution {
public:
    bool divisible(vector<int> &nums, int mid , int threshold){
        int sum = 0;
        for(int x : nums){
            sum += (x + mid - 1) / mid;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN;

        for (int x : nums) {
            
            maxi = max(maxi, x);
        }

        int low = 1;
        int high = maxi;

        while(low <= high){

            int mid = (low + high) / 2;

            if(divisible(nums, mid , threshold)){
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};