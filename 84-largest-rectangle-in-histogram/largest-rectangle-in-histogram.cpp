class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int n = heights.size();

      stack<int> st;

      int lsmall[n], rsmall[n];

      for(int i =0;i<n;i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }

        if(st.empty()) lsmall[i] = 0;
        else lsmall[i] = st.top() + 1;
        st.push(i);
      }  

    while(!st.empty()) st.pop(); //clear the stack

      for(int i = n-1;i >=0 ;i--){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }

        if(st.empty()) rsmall[i] = n-1;
        else rsmall[i] = st.top()- 1;
        st.push(i);
      }

      int maxArea = 0;
      for(int i =0 ;i <n;i++){
        maxArea = max(
            maxArea,
            heights[i] * (rsmall[i] - lsmall[i] + 1)
        );
      }
      return maxArea;
    }
};