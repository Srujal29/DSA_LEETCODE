class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        int target = sum - x;

        if (target < 0)
            return -1;

        if (target == 0)
            return nums.size();

        int lngarr = -1;

        int left = 0, curr = 0;
        for(int right = 0; right < nums.size();right++){
            curr += nums[right];

            while(curr > target){
                curr -= nums[left];
                left++;
            }

            if(curr == target){
                lngarr = max(lngarr, right- left+1);
            }
        }

        if (lngarr == -1)
            return -1;

        return nums.size() - lngarr;
    }
};