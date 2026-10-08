class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;

        for(int x : nums) {
            if(m.contains(x)) return true;
            m[x]++;
        }
        return false;
    }
};