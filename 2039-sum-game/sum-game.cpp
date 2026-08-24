class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int leftQ = 0;
        int rightQ = 0;
        int diff = 0;

        // First half
        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                diff += num[i] - '0';
        }

        // Second half
        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                diff -= num[i] - '0';
        }

        // Bob wins only in this case
        if (2 * diff == 9 * (rightQ - leftQ))
            return false;

        return true;
    }
};