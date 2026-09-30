class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> need(26,0);
        

        for(int i=0;i < s1.size();i++){
            need[s1[i] - 'a']++;
        }

        int l = 0, r = s1.size()-1;
        while(r < s2.size()){
            vector<int> window(26,0);
            for(int i=l;i<=r;i++){
                window[s2[i] - 'a']++;
            }
            if(need == window) return true;
            l++;
            r++;
        }
        return false;
    }
};