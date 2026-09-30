class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;
        int l = 0 , r = 0;
        int cnt = 0;
        int prod = 1;
        while(r < nums.size()){
            prod *= nums[r];

            while(prod >= k){
                prod /= nums[l];
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;

    }
};