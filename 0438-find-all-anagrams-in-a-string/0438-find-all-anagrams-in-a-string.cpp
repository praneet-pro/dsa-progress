class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
        vector<int> res;
        int freq[26] = {0};
        int k = p.size();
        int diff = 0;
        for(int i = 0; i < k; i++) {
            freq[p[i] - 'a']++;
            freq[s[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++)
            if(freq[i] != 0) diff++;
        if(diff == 0) res.push_back(0);
        for(int i = k; i < s.size(); i++) {
            if(freq[s[i] - 'a'] == 0) diff++;
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