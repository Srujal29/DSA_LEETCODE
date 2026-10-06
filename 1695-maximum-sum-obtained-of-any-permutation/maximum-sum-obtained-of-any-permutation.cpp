class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        int n = nums.size();

        vector<int> diff(n + 1, 0);

        for(int i=0;i<req.size();i++){
            diff[req[i][0]] += 1; 
            diff[req[i][1] + 1] -= 1; 
        }

        vector<int> prefix(n);
        int freq = 0;
        for(int i=0;i<n;i++){
            freq += diff[i];
            prefix[i] = freq;
        }

        sort(nums.begin(),nums.end());
        sort(prefix.begin(),prefix.end());

        long long ans = 0;
        for(int i = nums.size() - 1; i>= 0;i--){
            ans +=  1LL * nums[i] * prefix[i];
        }
       return ans % 1000000007;


    }
};