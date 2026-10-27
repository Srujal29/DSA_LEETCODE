class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));

        if (m == 1 || n == 1) {
            return vector<string>(m, string(n, '.'));
        }

        for (int i = 0; i < m; i++) {
            int j = min(i, n - 1);

            ans[i][j] = '.';

            if (j + 1 < n) {
                ans[i][j + 1] = '.';
            }

            if (i == m - 1) {
                for (int k = j; k < n; k++) {
                    ans[i][k] = '.';
                }
            }
        }

        return ans;
    }
};