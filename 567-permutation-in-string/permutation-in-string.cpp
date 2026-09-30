class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int>need(26,0);
        vector<int>window(26,0);

        for(int i = 0 ; i < s1.size();i++){
            need[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        int l = 0 , r = s1.size() -1 ;
        while(r < s2.size()){
            if(need == window) return true;

            window[s2[l] - 'a']--;
            l++;
            r++;

            if(r < s2.size())
                window[s2[r] - 'a']++;

        }
        return false;
    }
};