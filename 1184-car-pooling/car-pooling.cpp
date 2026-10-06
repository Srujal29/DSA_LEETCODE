class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);
        
        for(int i=0;i < trips.size();i++){
            int from = trips[i][1];
            int to = trips[i][2];

            int pass = trips[i][0];

            diff[from] += pass;
            diff[to] -= pass;
        }

        int passenger = 0;
        for(int i : diff){
            passenger += i;

            if(passenger > capacity) return false;
        }

        return true;
    }
};