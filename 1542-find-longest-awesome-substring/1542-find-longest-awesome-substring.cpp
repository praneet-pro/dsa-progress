/*
Approach: Prefix XOR + Bitmask

Invariant:
- Each prefix has a bitmask representing odd/even count of digits (0–9)
- A substring is "awesome" if its mask has at most one bit set

Explanation:
- Same mask  -> all digits occur even number of times
- Mask differs by 1 bit -> exactly one digit occurs odd number of times

Method:
- Store earliest index of each mask
- For every position:
    1. Check same mask
    2. Check masks with one bit flipped

Time Complexity: O(10 * n) ≈ O(n)
Space Complexity: O(2^10) ≈ O(1)
*/

class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> firstIndex;
        firstIndex[0] = -1;
        int mask = 0000000000, ans = 0;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == '0') mask ^= (1 << 0);
            else if(c == '1') mask ^= (1 << 1);
            else if(c == '2') mask ^= (1 << 2);
            else if(c == '3') mask ^= (1 << 3);
            else if(c == '4') mask ^= (1 << 4);
            else if(c == '5') mask ^= (1 << 5);
            else if(c == '6') mask ^= (1 << 6);
            else if(c == '7') mask ^= (1 << 7);
            else if(c == '8') mask ^= (1 << 8);
            else if(c == '9') mask ^= (1 << 9);

            for(int d = 0; d < 10; d++) {
                int newMask = mask ^ (1 << d);
                if(firstIndex.count(newMask))
                    ans = max(ans, i - firstIndex[newMask]);
            }

            if(firstIndex.count(mask))
                ans = max(ans, i - firstIndex[mask]);
            else 
                firstIndex[mask] = i;
        }
        return ans;
    }
};