/*
DP – Longest Increasing Subsequence (with count)

Invariant:
- len[i] = length of LIS ending at index i
- cnt[i] = number of LIS of length len[i] ending at i

Approach:
- For each i, check all j < i with nums[j] < nums[i]
- If len[j] + 1 > len[i]:
    → Found longer LIS, update length and copy count
- If len[j] + 1 == len[i]:
    → Found another way to form same LIS, add counts
- Final answer = sum of cnt[i] where len[i] == max LIS

Time: O(n^2)
Space: O(n)
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1);
        vector<int> cnt(n, 1);
        int maxLength = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(len[j] + 1 == len[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxLength = max(maxLength, len[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(len[i] == maxLength)
                ans += cnt[i];
        }
        return ans;
    }
};