class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff(s.size());

        for(int i = 0;i<s.size();i++){
            diff[i] = abs((s[i] - 'a') - (t[i] - 'a'));
        }

        int l = 0, r = 0;
        int cost = 0;
        int maxlen = 0;

        while(r < s.size()){
            cost += diff[r];

            while(cost > maxCost){
                cost -= diff[l];
                l++;
            }

            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};