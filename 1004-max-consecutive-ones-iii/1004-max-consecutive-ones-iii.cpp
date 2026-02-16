/*
Sliding Window

Invarient: The current window always contains atmost k zeros.
        
Approch:   
- Expand right pointer
- Shrink from left when invarient breaks
- Track max window length

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, ans = 0, zeros = 0;
        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] == 0) zeros++;
            while(zeros > k) {
                if(nums[left] == 0) zeros--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};