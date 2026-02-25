/*
Idea:
Use a 5-bit mask to track parity (odd/even) of vowels a,e,i,o,u.
Same mask at two indices means the substring between them has
all vowels appearing even number of times.

Invariant:
mask represents vowel parity from index 0 to i.

Approach:
- Start with mask = 0 (all vowels even).
- Toggle bit when a vowel appears.
- If mask seen before → update answer.
- Else store first index of mask.

Time: O(n)
Space: O(1)  // only 32 possible masks
*/

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> firstIndex;
        firstIndex[0] = -1;
        int ans =  0;
        int mask = 0;

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == 'a') mask ^= (1 << 0);
            else if(c == 'e') mask ^= (1 << 1);
            else if(c == 'i') mask ^= (1 << 2);
            else if(c == 'o') mask ^= (1 << 3);
            else if(c == 'u') mask ^= (1 << 4);

            if(firstIndex.count(mask))
                ans = max(ans, i - firstIndex[mask]);
            else 
                firstIndex[mask] = i;
        }
        return ans;
    }
};