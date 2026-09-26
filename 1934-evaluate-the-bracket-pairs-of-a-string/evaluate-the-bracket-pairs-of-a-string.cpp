class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        int n = knowledge.size();
        for(int i=0;i<n;i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
 
 
        string ans = "";
        bool bst = false;
        for(int i=0;i<s.size();i++){
            string key ="";
            if(s[i] == '('){
                int j = i + 1;
                while(s[j] != ')'){
                    key += s[j];
                    j++;
                }
                i = j;
 
                 if(mp.find(key) != mp.end()){
                ans += mp[key];
            }else{
                ans += '?';
            }
            }
 
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};