class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;

        int l = 0, r = 0;
        int maxsum = 0;
        int sum = 0;

        while(r < nums.size()){
            mp[nums[r]]++;
            sum += nums[r];
            while(mp[nums[r]] > 1){
                mp[nums[l]]--;
                sum -= nums[l];
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            maxsum = max(maxsum , sum);
            r++;
        }
        return maxsum;
    }
};