class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //find the window in whcih at max only 1 sero is there

        int l=0, r=0;
        int zero = 0;
        int maxlen = 0;

        while(r < nums.size()){
            if(nums[r] == 0) zero++;

            while(zero > 1){
                if(nums[l] == 0) zero--;
                l++;
            }

            maxlen = max(maxlen , r-l);
            r++;
        }
        return maxlen;

    }
};