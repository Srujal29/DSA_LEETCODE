class Solution {
public:

    int maximumUnits(vector<vector<int>>& val, int capacity) {

        sort(val.begin(), val.end() ,[](vector<int> a, vector<int> b){
            return a[1] > b[1]; 
        });
        
        int totalValue = 0;
        
        for(int i =0 ; i <val.size();i++){
            if(val[i][0] <= capacity) {
                totalValue += val[i][0] * val[i][1];
                capacity -= val[i][0];
            }
            else {
                totalValue += capacity * val[i][1];
                break;
            }
        }
        
        return totalValue; 
    }
};