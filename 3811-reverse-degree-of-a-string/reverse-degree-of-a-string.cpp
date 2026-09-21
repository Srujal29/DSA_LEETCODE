class Solution {
public:
    int reverseDegree(string s) {
        int degree = 0;

       for(int i=0;i<s.size();i++){
            degree += (i+1) * (26 - (s[i] - 'a'));
       }

       return degree; 
    }
};