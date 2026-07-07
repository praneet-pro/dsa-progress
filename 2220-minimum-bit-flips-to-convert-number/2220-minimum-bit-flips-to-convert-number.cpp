class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        int count = 0;

        while(x) {
            x = x & (x - 1);
            count++;
        }
        return count;   // return __builtin_popcount(start ^ goal)
    }
};