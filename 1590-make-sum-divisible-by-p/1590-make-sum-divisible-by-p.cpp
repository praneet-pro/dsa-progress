class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for(int x : nums) sum += x;
        int target = sum % p;
        if(target == 0) return -0;
        unordered_map<int, int> index;
        index[0] = -1;
        int minLen = nums.size();
        int needed = 0, cur_rem = 0;
        for(int i = 0; i < nums.size(); i++) {
            cur_rem = (cur_rem + nums[i]) % p;
            needed = (cur_rem - target + p) % p;
            if(index.count(needed)) minLen = min(minLen, i - index[needed]);
            index[cur_rem] = i;
        }
        return minLen == nums.size() ? -1 : minLen;
    }
};