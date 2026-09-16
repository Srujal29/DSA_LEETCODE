class Solution {
public:
    int helper(vector<int> &arr, long long pages){
          int students = 1;
          long long pageStudent = 0;

          for(int i=0;i < arr.size();i++){

            if(pageStudent + arr[i] <= pages){
                pageStudent += arr[i];
            }else{
                students++;
                pageStudent = arr[i];

            }
          }
          return students;
      }
        int findPages(vector<int> &arr, int k) {
            int n = arr.size();

            if(n < k) return -1;

            long long low = INT_MIN , high = 0;
            for(int x : arr){
                 low = max(low, (long long)x);
                 high += x;
            }

            while(low <= high){
                long long mid = (low + high) / 2;

                int students = helper(arr,mid);

                if(students > k){
                    low = mid + 1;
                }else high = mid - 1;
            }

            return low;
        }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, k);
    }
};