/*
Prefix Sum + HashMap

Invariant:
- freq[p] stores how many times a prefix sum 'p' has occurred so far.

Approach:
- Initialize freq[0] = 1 to represent an empty prefix.
- Traverse the array while maintaining a running prefix sum.
- For each prefix sum 'sum':
    - If (sum - k) exists in freq, it means there are
      freq[sum - k] subarrays ending at current index with sum = k.
    - Add freq[sum - k] to the answer.
- Update freq[sum] after processing the current element.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int sum = 0, count = 0;
        for(int x : nums) {
            sum += x;
            if(freq.count(sum - k)) count += freq[sum - k];
                freq[sum]++;
        }
        return count;
    }
};