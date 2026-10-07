class Solution {
public:
    void helper(string &s, int i , int bal , int open , int close , string curr, set<string> &ans){
        if(i == s.size()){
            if(bal == 0 && open == 0 && close ==0) {
                ans.insert(curr);
            }
            return;
        }


        if(s[i] == '('){
            //keep
            helper(s,i+1, bal + 1, open,close, curr + '(', ans);

            //remove
            if(open > 0){
                helper(s,i+1,bal, open - 1, close, curr, ans);
            }
        }
        else if(s[i] == ')'){
            //keep
            if(bal > 0){
                 helper(s,i+1, bal - 1, open,close, curr + ')', ans);
            }

            //remove
            if(close > 0){
                helper(s,i+1,bal, open, close-1, curr , ans);
            }
        }
        else{
            helper(s,i+1, bal,open,close, curr+s[i], ans);
        }

    }
    vector<string> removeInvalidParentheses(string s) {
        int open = 0;
        int close = 0;
        for(char c : s){
            if(c == '(') open++;
            else if(c == ')'){
                if(open > 0) open--;
                else close++;
            }
        }
        set<string> ans;
        string curr = "";
        helper(s, 0 ,0 , open ,close, curr, ans);
        return vector<string>(ans.begin(), ans.end());
    }
};