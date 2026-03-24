class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }
        unordered_map<int, int> freq;
        freq[0] = 1;
        int sum = 0;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(hash.find(complement) != hash.end() && hash[complement] != i)
                return {i, hash[complement]};
        }
        return {};
    }
};