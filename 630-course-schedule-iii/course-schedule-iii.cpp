class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
         sort(courses.begin(), courses.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        priority_queue<int> pq;

        int ans = 0; 
        int days = 0;

        for(int i=0;i<courses.size();i++){
            int duration = courses[i][0];
            int lastdate = courses[i][1];

            days += duration;
            pq.push(duration);
            ans++;

            if(days > lastdate){
                days -= pq.top();
                pq.pop();
                ans--;
            }
        }

        return ans;
    }
};