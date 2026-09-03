class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        int minOdd = INT_MAX;
        for(int x : nums1){
            if(x % 2 == 1) minOdd = min(minOdd, x);
        }

        bool makeOdd = true;

        for(int i=0;i<nums1.size();i++){
            if(nums1[i] % 2 == 0){
                if(minOdd == INT_MAX || nums1[i] <= minOdd){
                    makeOdd = false;
                    break;
                }
            }
        }

        bool makeEven = true;
        for(int i =0;i<nums1.size();i++){
            if(nums1[i] % 2 ==1){
                if(minOdd == INT_MAX || nums1[i] <= minOdd){
                    makeEven = false;
                    break;
                }
            }
        }

       return makeOdd || makeEven;
    }
};