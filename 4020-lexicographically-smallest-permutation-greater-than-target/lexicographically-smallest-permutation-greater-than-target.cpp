class Solution {
public:

    string makeAnswer(string prefix, int c, vector<int>& cnt) {
        string ans = prefix;

        // Put the character that makes us greater
        ans += char('a' + c);
        cnt[c]--;

        // Fill remaining characters in smallest order
        for (int i = 0; i < 26; i++) {
            while (cnt[i] > 0) {
                ans += char('a' + i);
                cnt[i]--;
            }
        }

        return ans;
    }

    string lexGreaterPermutation(string s, string target) {

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        string prefix = "";

        int i = 0;

        // Step 1: Try to match target as long as possible
        for (; i < target.size(); i++) {

            int x = target[i] - 'a';

            // We can match target[i]
            if (cnt[x] > 0) {
                prefix += target[i];
                cnt[x]--;
            }
            else {
                break;
            }
        }

        // Step 2:
        // At position i, try to put the smallest
        // character greater than target[i].
        if (i < target.size()) {

            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (cnt[c] > 0) {
                    return makeAnswer(prefix, c, cnt);
                }
            }
        }

        // Step 3:
        // We couldn't increase at position i.
        // Backtrack to previous positions.
        for (int j = i - 1; j >= 0; j--) {

            // Restore the character we used at j
            cnt[prefix[j] - 'a']++;

            int x = target[j] - 'a';

            // Try the smallest character > target[j]
            for (int c = x + 1; c < 26; c++) {

                if (cnt[c] > 0) {

                    string pre = target.substr(0, j);

                    return makeAnswer(pre, c, cnt);
                }
            }
        }

        return "";
    }
};