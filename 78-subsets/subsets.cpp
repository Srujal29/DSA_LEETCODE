class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subset = 1 << nums.size();    //2 ki power n

        vector<vector<int>> ans;

        for(int i=0;i < subset;i++){
            vector<int> curr;
            for(int j=0;j<nums.size();j++){
                if(i & (1 << j)){
                    curr.push_back(nums[j]);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};