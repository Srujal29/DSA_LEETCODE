class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, unordered_set<int>> mp;

        for(auto &seat : reservedSeats){
            mp[seat[0]].insert(seat[1]);
        }

        long long ans = 2LL *  (n - mp.size());

        for(auto &[rows,seats] : mp){
           bool leftfree = true; 
           bool middlefree = true; 
           bool rightfree = true; 

           for(int s = 2; s<=5;s++){
                if(seats.count(s)){
                    leftfree = false;
                    break;
                }
           }
           for(int s = 2; s<=5;s++){
                if(seats.count(s)){
                    leftfree = false;
                    break;
                }
           }
           for(int s = 4; s<=7;s++){
                if(seats.count(s)){
                    middlefree = false;
                    break;
                }
           }
           for(int s = 6; s<=9;s++){
                if(seats.count(s)){
                    rightfree = false;
                    break;
                }
           }

           if(leftfree && rightfree){
            ans += 2;
           }else if(leftfree || middlefree || rightfree){
            ans += 1;
           }
        }
        return ans;
    }
};