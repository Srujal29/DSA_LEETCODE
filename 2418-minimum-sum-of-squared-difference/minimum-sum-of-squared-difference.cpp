
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        int mx = 0;

        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        long long total = 0;
        for(int x : diff) {
            total += x;
        }

        if(k >= total) return 0;

        int l = 0, r = mx;

        while(l < r) {
            int mid = l + (r - l) / 2;
            long long ops = 0;

            for(int x : diff) {
                if(x > mid)
                    ops += x - mid;
            }

            if(ops <= k)
                r = mid;
            else
                l = mid + 1;
        }

        int target = l;
        long long used = 0;
        long long ans = 0;

        for(int x : diff) {
            if(x > target) {
                used += x - target;
                x = target;
            }
            ans += 1LL * x * x;
        }

        k -= used;

        for(int i = 0; i < n && k > 0; i++) {
            if(diff[i] >= target && target > 0) {
                ans -= 1LL * target * target;
                ans += 1LL * (target - 1) * (target - 1);
                k--;
            }
        }

        return ans;
    }
};
