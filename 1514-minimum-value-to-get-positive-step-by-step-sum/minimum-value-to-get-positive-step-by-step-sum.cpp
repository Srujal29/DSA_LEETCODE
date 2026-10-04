class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefix = 0;
        int mini = 0;

        for(int x : nums){
            prefix += x;
            mini = min(mini, prefix);
        }

        return 1 - mini;
    }
};