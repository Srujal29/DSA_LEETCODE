class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(), [&](auto& a, auto& b) {
            int s1 = 0;
            int s2 = 0;
            int x = a.first;
            int y = b.first;

            while (x > 0) {
                s1 += x % 10;
                x /= 10;
            }
            while (y > 0) {
                s2 += y % 10;
                y /= 10;
            }

            if (s1 != s2)
                return s1 < s2;

            return a.first < b.first;
        });

        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[arr[i].second] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            while (pos[i] != i) {
                int j = pos[i];

                swap(arr[i], arr[j]);
                pos[arr[i].second] = i;
                pos[arr[j].second] = j;

                swaps++;
            }
        }

        return swaps;
    }
};