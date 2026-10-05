class Solution {
public:
    int scoreOfParentheses(string s) {
        int cnt = 0;

        int depth = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                depth++;

            } else {
                if (s[i - 1] == '(') {
                    cnt += pow(2, depth - 1);
                }
                depth--;
            }
        }

        return cnt;
    }
};