class Solution {
public:
    void helper(string curr, int open , int close ,vector<string> &res, int n ){

    if(curr.size() == 2 * n){
        res.push_back(curr);
        return;
    }
        if(open < n) helper(curr+'(', open+1,close, res,n);
        if(close < open) helper(curr+')',open,close+1, res,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int open = 0 ,close = 0;
      

        helper("",open ,close,res,n);
        return res;
    }
};