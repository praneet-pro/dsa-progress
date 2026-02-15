class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(p.length() > s.length()) return {};
        int freq[26] = {0};
        int k = p.length();
        for(char c : p) freq[c - 'a']++;
        for(int i =  0; i < k; i++) freq[s[i] - 'a']--;
        int diff = 0;
        for(int i = 0; i < 26; i++) 
            if(freq[i] != 0) diff++;
        if(diff == 0) res.push_back(0);
        for(int i = k; i < s.length(); i++) {
            if(freq[s[i]-'a'] == 0) diff++;
            freq[s[i] - 'a']--;
            if(freq[s[i] - 'a'] == 0) diff--;
            if(freq[s[i - k] - 'a'] == 0) diff++;
            freq[s[i - k] - 'a']++;
            if(freq[s[i - k] - 'a'] == 0) diff--;
            if(diff == 0) res.push_back(i - k + 1);
        }
        return res;
        }
};