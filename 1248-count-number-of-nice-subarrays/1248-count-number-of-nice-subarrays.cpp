/*
Sliding Window

Invarient: The number of odd numbers in the window is always <= k.

Approach: 
- Count the number of subarrays with odd <= k  using sliding window.
- Expand the window by moving right and counting the number of odd.
- Shrink the window from the left while odd > k.
- For each valid window, all subarrays ending at right are valid:
  count += (right - left + 1).
- Number of subarrays with exact odd numbers equal to k is computed as:
  atMost(k) - atMost(k - 1).

Time Complexity: O(n)
Space Compexcity: O(1)
*/

class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int left = 0, count = 0, odd = 0;
        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] % 2 == 1) odd++;
            while(odd > k) {
                if(nums[left] % 2 == 1) odd--;
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};