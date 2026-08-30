class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = 0;
        int maxIdx = 0;

        for(int i=1;i<nums.size();i++){
            if(nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
            if(nums[i] < nums[minIdx]){
                minIdx = i;
            }
        }

        int left = min(minIdx,maxIdx);
        int right = max(minIdx,maxIdx);

        int n = nums.size();

        return min({
            right+1,
            n-left,
            left+1+n-right
        });
    }
};