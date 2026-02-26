class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> firstIndex;
        firstIndex[0] = -1;
        int ans = 0;
        int mask = 0000000000;

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];

            if(c == '0') mask^= (1 << 0);
            else if(c == '2') mask ^= (1 << 1);
            else if(c == '3') mask ^= (1 << 2);
            else if(c == '4') mask ^= (1 << 3);
            else if(c == '5') mask ^= (1 << 4);
            else if(c == '5') mask ^= (1 << 4);
            else if(c == '5') mask ^= (1 << 4);

        }
    }
};