class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int has_zero = 0;
        for(int x : nums) {
            if(x != 0) {
                product *= x;
            } else {
                has_zero++;
            }
        }

        vector<int> ans(nums.size(), 0);
        if(has_zero > 1) return ans;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0 && !has_zero) {
                ans[i] = product / nums[i];
            } else if(has_zero && nums[i] == 0) {
                ans[i] = product;
            }
        }
        return ans;
    }
};