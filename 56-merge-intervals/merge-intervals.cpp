class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        //brute
        // for(int i =0;i<n;i++){
        //     int start = intervals[i][0];
        //     int end = intervals[i][1];
        //     if(!ans.empty() && end <= ans.back()[1]){ // already inside the range so we just skip it 
        //         continue;
        //     }
        //     for(int j=i+1;j<n;j++){
        //         if(intervals[j][0] <= end){ // agla wala ka first end se choa hai to update karan padega end dobo me se jobhi bada rahega wo 
        //             end = max(end, intervals[j][1]);
        //         }else{
        //             //else we can break it 
        //             break;
        //         }
        //     }
        //     ans.push_back({start,end});
        // }

        for(int i =0;i<n;i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};