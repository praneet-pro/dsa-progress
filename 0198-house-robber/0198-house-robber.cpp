class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> cache(nums.size() + 1, -1);
        return getCash(0, nums, cache);
    }

    int getCash(int index, vector<int>& houses, vector<int>& cache) {
        if(index >= houses.size()) return 0;

        if(cache[index] != -1)
            return cache[index];

        

        int scoutA = houses[index] + getCash(index + 2, houses, cache);
        int scoutB = getCash(index + 1, houses, cache);

        cache[index] = max(scoutA, scoutB);

        return max(scoutA, scoutB);
    }
};