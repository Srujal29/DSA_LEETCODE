class Solution {
public: 
    int helper(string answerKey, int k , char ch){
        int maxcount = 0;
        int l = 0, r = 0;
        int falsecount = 0;

        while(r < answerKey.size()){
            if(answerKey[r] == ch) falsecount++;

            while(falsecount > k){
                if(answerKey[l] == ch) falsecount--;
                l++;
            }
            if(falsecount <= k){
                
            maxcount = max(maxcount , r-l+1);
            }
            r++;
        }
        return maxcount;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maketrue = helper(answerKey, k, 'F');
        int makefalse = helper(answerKey, k, 'T');

        return max(maketrue, makefalse);
    }
};