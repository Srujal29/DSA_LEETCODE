class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int small = 0, equal  = 0;

        for(int i : nums){
            if(i < target) small++;
            else if(i == target) equal++;
        }

        vector<int> ans;

        for(int i =0 ;i < equal;i++){
            ans.push_back(small + i);
        }
        return ans;

    }
};