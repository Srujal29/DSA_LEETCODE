class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> exists(1001,0);

        for(int x : nums){
            exists[x]  = 1;
        }

        for(int i = k;i<exists.size();i+=k){
            if(!exists[i]){
                return i;
            }
          
        }
        return -1;
    }
};