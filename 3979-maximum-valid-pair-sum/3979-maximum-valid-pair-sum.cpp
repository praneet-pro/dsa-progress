class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int max_i = 0, maxSum = 0;

        for(int j = k; j < nums.size(); j++) {
            if(nums[j - k] > max_i) {
                max_i = nums[j - k];
            }
            int sum = max_i + nums[j];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};