/*
Sliding Window

Invariant:
The sum of the current window is always <= goal.

Approach:
- Count the number of subarrays with sum <= goal using a sliding window.
- Expand the window by moving right and adding nums[right] to sum.
- Shrink the window from the left while sum > goal.
- For each valid window, all subarrays ending at right are valid:
  count += (right - left + 1).
- Number of subarrays with sum exactly equal to goal is computed as:
  atMost(goal) - atMost(goal - 1).

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int left = 0, sum = 0, count = 0;
        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while(sum > goal) {
                sum -= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};