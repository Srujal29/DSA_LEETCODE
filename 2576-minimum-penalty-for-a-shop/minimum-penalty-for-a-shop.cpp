class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int> lpen(n + 1, 0);
        vector<int> rpen(n + 1, 0);

        // Number of N before i
        for(int i = 1; i <= n; i++){
            lpen[i] = lpen[i-1];

            if(customers[i-1] == 'N'){
                lpen[i]++;
            }
        }

        // Number of Y from i onward
        for(int i = n-1; i >= 0; i--){
            rpen[i] = rpen[i+1];

            if(customers[i] == 'Y'){
                rpen[i]++;
            }
        }

        int minPenalty = INT_MAX;
        int ans = 0;
        for(int i= 0; i <= n ;i++){
            int penalty = lpen[i] + rpen[i];

            if(penalty < minPenalty){
                minPenalty = penalty;
                ans = i;
            }
        }

        return ans;
    }
};