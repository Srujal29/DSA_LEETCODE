class Solution {
public:
    bool check(vector<int>& nums, vector<int>& s, int i, int k) {
        vector<int> lps(k, 0);

        for(int a = 1, len = 0; a < k;) {
            if(s[i + a] == s[i + len]) {
                lps[a++] = ++len;
            } else if(len > 0) {
                len = lps[len - 1];
            } else {
                lps[a++] = 0;
            }
        }

        int a = 0, b = 0;

        while(a < 2 * k - 1) {
            if(nums[i + a % k] == s[i + b]) {
                a++;
                b++;
            }

            if(b == k) return true;

            if(a < 2 * k - 1 && nums[i + a % k] != s[i + b]) {
                if(b > 0) {
                    b = lps[b - 1];
                } else {
                    a++;
                }
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> s = nums;
        sort(s.begin(), s.end());

        int sum = 0;

        for(int k = 1; k <= n; k++) {
            if(n % k != 0) continue;

            bool valid = true;

            for(int i = 0; i < n; i += k) {
                if(!check(nums, s, i, k)) {
                    valid = false;
                    break;
                }
            }

            if(valid) sum += k;
        }

        return sum;
    }
};