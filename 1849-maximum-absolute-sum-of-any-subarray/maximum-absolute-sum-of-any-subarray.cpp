class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefix = 0;
        int minpre = 0;
        int maxpre = 0;

        int ans =0 ;
        for(int i=0;i<nums.size();i++){
            prefix += nums[i];

            int postive = prefix - minpre;
            int negative = maxpre - prefix ;

            minpre = min(prefix,minpre);
            maxpre = max(prefix,maxpre);

            ans= max(ans, max(postive,negative));
        }
        return ans;
    }
};