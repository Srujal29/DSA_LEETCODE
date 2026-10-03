class Solution {
public:
    int longestValidParentheses(string s) {
       int bal = 0; 
       int len = 0;
       int ans = 0;

       for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                bal++;
            }
            else{
                bal--;
            }

            len++;

            if(bal == 0){
                ans = max(ans,len);
            }

            if(bal < 0){
                bal = 0;
                len = 0;
            }
       } 
       bal = 0;
       len = 0;

       for(int i=s.size() - 1;i >= 0;i--){
            if(s[i] == ')'){
                bal++;
            }
            else{
                bal--;
            }

            len++;

            if(bal == 0){
                ans = max(ans,len);
            }

            if(bal < 0){
                bal = 0;
                len = 0;
            }
       } 

       return ans;

    }
};