class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
       long long ans1 = 1LL * cost1 * need1 + 1LL * cost2 * need2;

       long long comm = min(need1,need2);

       long long rem = abs(need1-need2);

       long long ans2 = comm * costBoth;

       if(need1 > need2){
        ans2 += rem * cost1;
       } 
       if(need2 > need1){
        ans2 += rem * cost2;
       } 

       long long ans3 = 1LL* max(need1,need2) * costBoth;

       return min({ans1, ans2, ans3});
    }
};