class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {

        const long long NEG = LLONG_MIN / 4;

        // flat[t]   = no active transaction, t transactions remaining
        // normal[t] = bought, t transactions remaining
        // shortPos[t] = short-sold, t transactions remaining

        vector<long long> flat(k + 1, NEG);
        vector<long long> normal(k + 1, NEG);
        vector<long long> shortPos(k + 1, NEG);

        flat[k] = 0;

        for (int price : prices) {

            vector<long long> newFlat = flat;
            vector<long long> newNormal = normal;
            vector<long long> newShort = shortPos;

            for (int cap = 1; cap <= k; cap++) {

                // Start normal transaction
                newNormal[cap] = max(
                    newNormal[cap],
                    flat[cap] - price
                );

                // Start short transaction
                newShort[cap] = max(
                    newShort[cap],
                    flat[cap] + price
                );

                // Complete normal transaction
                newFlat[cap - 1] = max(
                    newFlat[cap - 1],
                    normal[cap] + price
                );

                // Complete short transaction
                newFlat[cap - 1] = max(
                    newFlat[cap - 1],
                    shortPos[cap] - price
                );
            }

            flat = move(newFlat);
            normal = move(newNormal);
            shortPos = move(newShort);
        }

        long long ans = 0;

        for (int cap = 0; cap <= k; cap++) {
            ans = max(ans, flat[cap]);
        }

        return ans;
    }
};