class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;
        
        if(target == 0) return nums.size();
        if(target < 0) return -1;

        int l = 0, maxLen = -1, sum = 0;
        for(int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while(sum > target) {
                sum -= nums[l];
                l++;
            }
            if(sum == target)
                maxLen = max(maxLen, r - l + 1);
        }
        return maxLen == -1 ? -1 :nums.size() - maxLen;
    }
};