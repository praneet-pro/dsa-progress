class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n + 1, -1);
        return sendScouts(n, cache);
    }

private: 
    int sendScouts(int stairs_left, vector<int>& cache) {
        // base conditions
        if(stairs_left == 0) return 1;
        if(stairs_left <= -1) return 0;

        // check whether we've already calculated the path
        if(cache[stairs_left] != -1)
            return cache[stairs_left];

        // recusion for 1 and 2 stairs
        int left_path = sendScouts(stairs_left - 1, cache);
        int right_path = sendScouts(stairs_left - 2, cache);
        // calculation of the distinct ways for that path
        cache[stairs_left] = right_path + left_path;

        return cache[stairs_left];
    }

};