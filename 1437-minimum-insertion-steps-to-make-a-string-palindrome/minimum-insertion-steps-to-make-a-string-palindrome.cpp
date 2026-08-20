class Solution {
public:
    int longPalindrome(string s){
        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.size();
        vector<int> prev(n+1,0), curr(n+1,0);
        
        for(int i=1; i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == rev[j-1]){
                    curr[j] = 1 + prev[j-1];
                }else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
    int minInsertions(string s) {
        return s.size() - longPalindrome(s);
    }
};