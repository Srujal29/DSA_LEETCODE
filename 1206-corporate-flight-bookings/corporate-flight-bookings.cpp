class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1, 0 );

        for(int i=0;i< bookings.size();i++){
            int first = bookings[i][0];
            int last = bookings[i][1];

            diff[first] += bookings[i][2];
             if(last + 1 <= n) {
                diff[last + 1] -= bookings[i][2];
            }
        }

        vector<int> ans(n);
        int sum = 0;

        for(int i=1;i<=n;i++){
            sum += diff[i];
            ans[i-1] = sum;
        }
        return ans;
    }
};