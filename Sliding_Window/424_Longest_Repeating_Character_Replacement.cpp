class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, max_freq = 0, ans = 0;
        int freq[26] = {0};
        for(int right = 0; right < s.length(); right++) {
            freq[s[right] - 'A']++;
            max_freq = max(max_freq, freq[s[right] - 'A']);
            while((right - left + 1) - max_freq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
