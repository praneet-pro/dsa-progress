class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        int input[26];
        int target[26];

        for(int i = 0; i < s.size(); i++) {
            input[s[i] - 'a']++;
            target[t[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(input[i] != target[i]) return false;
        }
        return true;
    }
};