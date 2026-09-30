class Solution {
public:

    vector<int> findAnagrams(string s1, string s2) {
        vector<int> ans;
        
        if(s2.size() > s1.size())
            return ans;
        vector<int>need(26,0);
        vector<int>window(26,0);

        for(int i = 0 ; i < s2.size();i++){
            need[s2[i] - 'a']++;
            window[s1[i] - 'a']++;
        }

        int l = 0 , r = s2.size() -1 ;
        while(r < s1.size()){
            if(need == window){
                ans.push_back(l);
            }

            window[s1[l] - 'a']--;
            l++;
            r++;

            if(r < s1.size())
                window[s1[r] - 'a']++;

        }
        return ans;
    }
};