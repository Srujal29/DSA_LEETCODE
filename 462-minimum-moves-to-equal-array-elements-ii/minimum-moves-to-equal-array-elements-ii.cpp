class Solution {
public:
    int minMoves2(vector<int>& nums) {
      sort(nums.begin(), nums.end());

      int mid = nums.size() / 2;
      int med = nums[mid];

      int ans =0;
      for(int i : nums){
        ans += abs(i- med);
      }  
      return ans;
    }
};