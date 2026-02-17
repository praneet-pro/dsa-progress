/*
Sliding Window

Invariant:
- The product of elements in the current window is strictly less than k.

Approach:
- Expand the window by moving the right pointer and multiply the product.
- If the product becomes >= k, shrink the window from the left until
  the invariant is restored.
- For each valid window, count all subarrays ending at the right pointer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int left = 0, count = 0;
        long long product = 1;
        for(int right = 0; right < nums.size(); right++) {
            product *= nums[right];
            while(product >= k) {
                product /= nums[left];
                left++;
            }
            // all subarrays ending at right are valid
            count += (right - left + 1);
        }
        return count;
    }
};