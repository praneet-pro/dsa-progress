class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int max_streak = 0;

        for(int x : seen) {
            if(!seen.contains(x - 1)) {
                int curr_num = x;
                int curr_streak = 1;

                while(seen.contains(curr_num + 1)) {
                    curr_streak++;
                    curr_num++;
                }
                max_streak = max(max_streak, curr_streak);
            }
        }
        return max_streak;
    }
};