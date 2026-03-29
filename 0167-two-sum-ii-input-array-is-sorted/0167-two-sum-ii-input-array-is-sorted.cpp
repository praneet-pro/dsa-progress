class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(right > left) {
            int sum = nums[right] + nums[left];
            if(sum == target) return {left + 1, right + 1};
            if(sum > target) right--;
            else left++;
        }
        return {-1, -1};
    }
};