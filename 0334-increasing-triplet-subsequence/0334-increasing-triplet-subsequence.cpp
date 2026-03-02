/*
Topic: Greedy / State Compression

Invariant:
- first  = smallest value seen so far
- second = smallest possible value > first

Idea:
- Try to build an increasing sequence of length 3
- Update first and second greedily to keep them minimal
- If we ever find a number > second → triplet exists

Why this works:
- Smaller first/second gives more room for a third number
- We don’t need the actual sequence, only existence

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for(int x : nums) {
            if(x <= first) first = x;
            else if(x <= second) second = x;
            else return true;
        }
        return false;
    }
};