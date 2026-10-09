class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int x : nums) m[x]++;

        vector<vector<int>> bucket(nums.size() + 1);
        for(auto& [key, freq] : m) {
            bucket[freq].push_back(key);
        }

        vector<int> ans;
        for(int i = bucket.size() - 1; i >= 0 && ans.size() < k; i--) {
            for(int num : bucket[i]) {
                ans.push_back(num);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};