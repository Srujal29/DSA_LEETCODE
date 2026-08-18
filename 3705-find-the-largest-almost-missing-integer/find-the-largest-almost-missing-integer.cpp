class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == k){
            int maxi = nums[0];
            for(int i =1;i < n;i++){
                if(nums[i] > maxi) maxi = nums[i];
            }

            return maxi;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        if(k == 1){
            int maxi = -1;
            for(auto it : mp){
                if(it.second == 1){
                    maxi = max(maxi, it.first);
                }
            }
            return maxi;
        }
        int ans = -1;
    
        if (mp[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (mp[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};