/*
Topic: Monotonic Stack (Next Greater Element)

Invariant:
- The stack maintains elements in strictly decreasing order (top → bottom).
- All elements in the stack are waiting to find their next greater element
  to the right.

Approach:
- Traverse nums2 from left to right.
- For each element:
- While it is greater than the stack top, it is the next greater element
  for the stack top → pop and record the answer.
- Push the current element into the stack.
- Elements left in the stack have no next greater element → assign -1.
- Use a hashmap to answer queries for nums1 in O(1).

Time Complexity: O(n)
- Each element is pushed and popped at most once.

Space Complexity: O(n)
- Stack + hashmap in the worst case.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nxtGreater;
        stack<int> st;

        for(int x : nums2) {
            // Resolve waiting elements
            while(!st.empty() && x > st.top()) {
                nxtGreater[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        // Remaining elements have no next greater
        while(!st.empty()) {
            nxtGreater[st.top()] = -1;
            st.pop();
        }

        // Build answer for nums1
        vector<int> ans;
        for(int x : nums1) {
            ans.push_back(nxtGreater[x]);
        }
        return ans;
    }
};