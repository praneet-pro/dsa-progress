/*
Core Idea (Prefix Sum + Hashing):

Let prefixSum[i] be the sum of elements from index 0 to i.
The sum of a subarray (i+1 ... j) is:
    prefixSum[j] - prefixSum[i]

This subarray is divisible by k if:
    (prefixSum[j] - prefixSum[i]) % k == 0

Which implies:
    prefixSum[j] % k == prefixSum[i] % k

So:
Two prefix sums having the SAME remainder when divided by k
form a subarray whose sum is divisible by k.

------------------------------------------------------------

Approach:
- Maintain a running prefix sum.
- Convert each prefix sum into a remainder modulo k.
- Normalize the remainder to handle negative values:
      rem = ((sum % k) + k) % k
- Use a hashmap to store how many times each remainder has occurred.
- For each remainder:
      if it has appeared before, all those previous occurrences
      form valid subarrays ending at the current index.

Initialization:
- freq[0] = 1
  This accounts for subarrays starting from index 0.

------------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(k)  // at most k distinct remainders
*/


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int sum = 0, count = 0;
        for(int x : nums) {
            sum += x;
            int rem = ((sum % k) + k) % k;
            count += freq[rem];
            freq[rem]++;
        }
        return count;
    }
};