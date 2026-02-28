/*
Topic: Monotonic Stack (Next Greater Element)

Invariant:
The stack stores indices of days with temperatures
in strictly decreasing order (top = most recent unresolved day).

Approach:
- Traverse temperatures from left to right.
- While current temperature is higher than the temperature at stack top,
  resolve the answer for that index.
- Push current index into the stack.
- Remaining indices have no warmer future day → answer stays 0.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};