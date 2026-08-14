class Solution {
public:
    int maximumLengthSubstring(string s) {
       unordered_map<char,int> mp;

       int maxi = 0;
 
      int left = 0;
    int right = 0;
        while (right < s.size()){

            mp[s[right]]++;
            while(mp[s[right]] > 2){
                mp[s[left]]--;
                left++;
            }
            int len = right - left + 1;
            maxi = max(maxi, len);

            right++;
        }

        return maxi;
    }
};