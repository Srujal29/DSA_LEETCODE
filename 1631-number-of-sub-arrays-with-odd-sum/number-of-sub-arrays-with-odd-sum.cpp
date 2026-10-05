class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int prefix = 0;
        int even = 1;
        int odd = 0;

        long long ans = 0;


        for(int i = 0;i< arr.size();i++){
            prefix += arr[i];

            if(prefix % 2 == 0){
                ans += odd;
                even++;

            }
            else {
                ans += even;
                odd++;
            }
        }
        return ans % 1000000007;
       
    }
};