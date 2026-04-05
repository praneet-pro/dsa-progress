/* 
Sliding Window

Invarient: Find the maximux length of arrays by deleting one element

Approach: 
- Move the right pointer while counting zeros.
- Shrink the window when is zeros > 1.
- Calculate size using the formula (right - left) as 1 element is removed.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {    // Not replace Its DELETE
        int left = 0, maxLen = 0, zeros = 0;
        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] == 0) zeros++;
            while(zeros > 1) {
                if(nums[left] == 0) zeros--;
                left++;
            }
            maxLen = max(maxLen, right - left);
        }
        return maxLen;
    }
};