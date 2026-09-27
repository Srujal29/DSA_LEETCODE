class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<char> st;

        for(int i =0;i < s.size();i++){
            int j = i + 1;
            if(s[i] != ')') {
                st.push(s[i]);
            }
            else{
                string temp ="";
                while(st.top() != '('){
                    temp += st.top();
                    st.pop();
                    j++;
                }
                st.pop();
             
                for(int j = 0; j < temp.size(); j++) {
                    st.push(temp[j]);
                }
            }
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;

    }
};