class Solution {
public:
    string removeOuterParentheses(string s) {
       stack<int>st;
        int bal = 0;
        string curr = "";
        string ans = "";
       for(int i = 0; i < s.size();i++){

           st.push(s[i]);
           if(s[i] == '(') bal++;
           else bal--;

           if(bal == 0){
            while(!st.empty()){
                curr += st.top();
                st.pop();
            }
            reverse(curr.begin(), curr.end());
            ans += curr.substr(1,curr.size()-2);
            curr = "";
           }
       } 

       return ans;
    }
};