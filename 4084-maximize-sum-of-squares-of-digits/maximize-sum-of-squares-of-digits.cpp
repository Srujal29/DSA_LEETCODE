class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        string ans = "";
        if(num * 9 < sum ) return ans;
        for(int i=0;i<num;i++){
            int dig = min(9, sum);

            ans.push_back('0' + dig);
            sum -= dig;
        }
        return ans;
    }
};