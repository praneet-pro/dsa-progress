class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();           // we dont need the height of the bar which is greater

                int width;
                if(st.empty()) 
                    width = i;
                else
                    width = i - st.top() - 1;       // -1 because we pop the nxt element

                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};