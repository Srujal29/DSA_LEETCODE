class Solution {
public:
    /*
    for every lement if found increase the count else decrease the count whichever the remaing is the answer

    again iterate throh array cnt that element if greater than n/2 then is s the anserr
    */
    int majorityElement(vector<int>& nums) {
        int element;
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++){
            if(cnt==0){
                cnt = 1;
                element = nums[i];
            }
            else if(nums[i] == element){
                cnt++;
            }else{
                cnt--;
            }
        }
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == element){
                count++;
            }
        }

        if(count > (nums.size() / 2))return element;
        else return -1;
    }
};