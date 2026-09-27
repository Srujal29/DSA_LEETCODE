class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        vector<pair<double,int>> workers;

        for(int i =0;i < wage.size(); i++){
            double ratio = (double) wage[i]/(double) quality[i];
            workers.push_back({ratio, quality[i]});
        }

        sort(workers.begin(), workers.end());

        priority_queue<int> pq;

        int totalQuality = 0; 
        double ans = 1e18;

        for(auto worker : workers){
            double ratio = worker.first;
            int q = worker.second;

            pq.push(q);

            totalQuality += q;

            if(pq.size() > k){
                totalQuality -= pq.top();
                pq.pop();
                
            }
            if(pq.size() == k){
                ans = min(ans, totalQuality * ratio);

            }
        }

        return ans;
    }
};