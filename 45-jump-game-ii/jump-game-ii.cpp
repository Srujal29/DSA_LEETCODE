class Solution {
public:
    // int f(int idx, int jumps, vector<int> &nums){

    //     if(idx >= nums.size() -1) return jumps;

    //     int mini = INT_MAX;
    //     for(int i = 1;i <= nums[idx];i++){
    //         mini = min(mini , f(idx + i, jumps+1,nums));
    //     }
    //     return mini ;
    // }
    int jump(vector<int>& nums) {
        int left = 0 , right = 0;
        int jumps = 0;

        while(right < nums.size() -1){
            int farthest = 0;
            
            for(int idx = left; idx <= right; idx++){
                farthest = max(farthest , idx+ nums[idx]);
            }
            
            jumps++;
            left = right + 1;
            right = farthest;

        }

        return jumps;
    }
};