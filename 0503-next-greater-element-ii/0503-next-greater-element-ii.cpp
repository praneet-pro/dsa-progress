/*
Topic: Monotonic Stack (Next Greater Element – Circular Array)

Invariant:
The stack stores indices of elements whose next greater element
has not been found yet. Values in the stack are in decreasing order.

Approach:
- Traverse the array twice (0 to 2n-1) to simulate circular behavior.
- Use i % n to handle rotation.
- While current element is greater than stack top, resolve its answer.
- Push indices only during the first pass to avoid duplicates.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;  // stores indices

        for(int i = 0; i < 2*n; i++) {
            int idx = i % n;

            while(!st.empty() && nums[idx] > nums[st.top()]) {
                ans[st.top()] = nums[idx];
                st.pop();
            }

            if(i < n) 
                st.push(idx);
        }
        return ans;
    }
};