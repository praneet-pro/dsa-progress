/*
Prefix Sum + Hashing

Invariant:
If two prefix sums have the same remainder when divided by k,
the subarray between them has sum divisible by k.

Reason:
(prefix[j] - prefix[i]) % k == 0  ⇒  prefix[j] % k == prefix[i] % k

Approach:
- Store the FIRST index where each remainder appears.
- Initialize remainder 0 at index -1 to handle subarrays starting at index 0.
- While iterating, if the same remainder appears again and the
  distance between indices is ≥ 2, a valid subarray exists.

Time Complexity: O(n)
Space Complexity: O(min(n, k))
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(k == 0) {
            for(int i = 1; i < nums.size(); i++) {
                if(nums[i] == 0 && nums[i - 1] == 0) return true;
            }
            return false;
        }

        unordered_map<int, int> prefixSum;
        prefixSum[0] = -1;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;
            if(prefixSum.count(rem)) {
                if(i - prefixSum[rem] >= 2) 
                    return true;
            }
            else
                prefixSum[rem] = i;
        }
        return false;
    }
};