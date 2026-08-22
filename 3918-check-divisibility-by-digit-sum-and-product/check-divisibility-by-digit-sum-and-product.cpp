class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        int original  = n;
        while(n > 0){
            int dig = n % 10;
            sum += dig;
            product *= dig;
            n = n/10;
        }

        return original % (sum + product) == 0;
    }
};