class Solution {
public: 
    bool f(int i,int balance , string s, vector<vector<int>> &dp){
        if(balance  < 0 ) return false;

        if(i == s.size()){
            return balance == 0;
        }
        if(dp[i][balance] != -1) return dp[i][balance];

        if(s[i] == '(') return dp[i][balance] =  f(i+1, balance + 1, s, dp);

        if(s[i] == ')'){
            
                return dp[i][balance] = f(i+1, balance - 1,s, dp);
        }

        return dp[i][balance] =  f(i+1, balance + 1, s,dp) || f(i+1, balance - 1, s,dp) || f(i+1,balance, s,dp);

    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size() , vector<int> (s.size()+1,-1));
        return f(0 ,0 , s, dp);

    }
};