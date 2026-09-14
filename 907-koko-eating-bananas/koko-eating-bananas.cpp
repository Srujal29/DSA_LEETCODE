class Solution {
public:
    long long helper(vector<int> &piles, int perhrs){

        long long totalhrs = 0;
        for(int i=0;i < piles.size();i++){
            totalhrs += piles[i] / perhrs;

            if(piles[i] % perhrs != 0)
                totalhrs++;
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int high = INT_MIN;
        for(int x : piles){
            if(x > high) high = x;
        }

        int low = 1;
        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high -low) /2;
            long long totalhrs = helper(piles, mid);
            if(totalhrs <= h){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};