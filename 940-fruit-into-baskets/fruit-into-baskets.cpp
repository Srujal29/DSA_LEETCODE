class Solution {
public:
    int totalFruit(vector<int>& arr) {

        int l =0 , r =0, maxlen = 0;
        unordered_map<int,int>mp;
        
        while(r < arr.size()){
            
            mp[arr[r]]++;
            
            if(mp.size() > 2){
                mp[arr[l]]--;
                if(mp[arr[l]] == 0) mp.erase(arr[l]);
                l++;
            }
            
            if(mp.size() <= 2){
                maxlen = max(maxlen , r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};