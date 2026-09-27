class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

       vector<pair<int,int>> events;

       for(auto trip : trips){
        int pass = trip[0];
        int from = trip[1];
        int to = trip[2];

        events.push_back({from, pass});
        events.push_back({to, -pass});
       } 

       sort(events.begin(),events.end());

        int seats =0 ;

       for(auto eve : events){
        seats += eve.second;

        if(seats > capacity) return false;
       }

       return true;
    }
};