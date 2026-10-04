class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      unordered_map<int,int> mp;
      mp[0] = 1;

      int prefix = 0;
        int cnt = 0;

      for(int i=0;i<nums.size();i++){
        prefix += nums[i];

        int remainder = prefix % k;
        if(remainder < 0){
    remainder += k;
}
        if(mp.find(remainder) != mp.end()){
            cnt += mp[remainder];
        }

        mp[remainder]++;
      } 
      return cnt; 
    }
};