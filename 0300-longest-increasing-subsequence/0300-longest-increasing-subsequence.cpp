/*
Topic: Greedy + Binary Search

Invariant:
- tails[i] stores the minimum possible ending value of an
  increasing subsequence of length (i + 1).
- tails is always sorted.

Approach:
- Traverse the array.
- For each element x:
  - If x is greater than all elements in tails, extend the LIS.
  - Otherwise, replace the first element >= x using binary search
    to keep tails minimal.
- The size of tails gives the LIS length.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for(int x : nums) {
            auto it  = lower_bound(tails.begin(), tails.end(), x);
            if(it == tails.end()) 
                tails.push_back(x);
            else
                *it = x;
        }
        return tails.size();
    }
};