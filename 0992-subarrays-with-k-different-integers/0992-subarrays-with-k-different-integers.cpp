/* Sliding Window

Invariant:
The window always contains at most K distinct elements.

Approach:
- Use a sliding window with a frequency map.
- Expand the window to the right and include elements.
- If the number of distinct elements exceeds K, shrink the window from the left.
- For each valid window, all subarrays ending at right are valid:
  count += (right - left + 1)
- Number of subarrays with exactly K distinct elements =
  atMost(K) - atMost(K - 1)

Time Complexity: O(n)
Space Complexity: O(K)
*/

class Solution {
public:
    int atMost(vector<int>& nums, int k) {
            if(k == 0) return 0;
            int left = 0, count = 0;
            unordered_map<int, int> freq;

            for(int right = 0; right < nums.size(); right++) {
                freq[nums[right]]++;
                while(freq.size() > k) {
                    freq[nums[left]]--;
                    if(freq[nums[left]] == 0) freq.erase(nums[left]);
                    left++;
                }
                count += right - left + 1;
        }
            return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};