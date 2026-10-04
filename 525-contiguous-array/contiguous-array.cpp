class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0] = -1;

        int bal = 0; 
        int ans =0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1) bal++;
            else bal--;

            if(mp.find(bal) != mp.end()) {
                ans = max(ans, i - mp[bal]);
            }

            if(mp.find(bal) == mp.end()){
                mp[bal] = i;
            }
        }
        return ans;
    }
};