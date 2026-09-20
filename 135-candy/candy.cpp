class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        long long sum = n;
        int i = 1;

        while(i < n) {

            int up = 0;

            while(i < n && ratings[i] > ratings[i - 1]) {
                up++;
                i++;
            }

            int down = 0;

            while(i < n && ratings[i] < ratings[i - 1]) {
                down++;
                i++;
            }

            sum += 1LL * up * (up + 1) / 2;
            sum += 1LL * down * (down + 1) / 2;
            sum -= min(up, down);

            if(i < n && ratings[i] == ratings[i - 1]) {
                i++;
            }
        }

        return sum;
    }
};