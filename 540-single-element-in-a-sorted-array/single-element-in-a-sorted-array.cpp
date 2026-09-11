class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1,high = n - 2;

        while(low <= high){

            int mid = (low + high) /2 ;
            // aage piche wale element alag hai to yahi ans hua
            if(nums[mid] != nums[mid +1] && nums[mid] != nums[mid -1]) return nums[mid];

            //now i have to eleminate space so for that check for the odd idx of mid and if mid-1 eqal to mid then just eleminate left part i.e. low = mid + 1 else vice versa
            //and if iddx is even then check for the right 


            if((mid % 2 ==1 && nums[mid-1] == nums[mid]) ||( mid % 2 == 0 && nums[mid] == nums[mid + 1])){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return -1;
    }
};