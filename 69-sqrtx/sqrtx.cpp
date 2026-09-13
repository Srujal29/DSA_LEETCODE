class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long val = 1LL * mid * mid;
            if(val <= x){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        return high;
    }
};