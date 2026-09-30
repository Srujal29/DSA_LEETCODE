class Solution {
public:
    int maxVowels(string s, int k) {
       int maxcnt = 0 ;
       int l = 0 , r = 0;
        int cnt = 0;
       while(r < s.size()){
        if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u'){
            cnt++;
        }
        while((r-l+1) > k){
            if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u')
                cnt--;
            l++;
        }
        maxcnt = max(cnt,maxcnt);
        r++;
       } 
       return maxcnt;
    }
};