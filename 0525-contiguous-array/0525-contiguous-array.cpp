/*
Idea:
Convert the problem into finding the longest subarray with sum = 0.

- Treat 1 as +1 and 0 as -1.
- Equal number of 0s and 1s ⇒ sum becomes 0.

Prefix Sum + Hashing:
If the same prefix sum appears at two indices i and j,
then the subarray (i+1 ... j) has sum = 0.

We store the FIRST index of each prefix sum to maximize length.
Initialize prefixSum = 0 at index -1 to handle subarrays starting from 0.

Time: O(n)
Space: O(n)
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIndex;
        firstIndex[0] = -1;
        int ans = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 1 ? 1 : -1);
            if(firstIndex.count(sum)) 
                ans = max(ans, i - firstIndex[sum]);
            else 
                firstIndex[sum] = i;
        }
        return ans;
    }
};