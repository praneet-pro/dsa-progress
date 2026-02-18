/* Sliding Window

Invariant:
The window is valid if it contains all characters of t
with required frequencies (formed == required).

Approach:
- Count required frequencies from t.
- Expand the window to include characters until valid.
- Once valid, shrink from left to minimize length.
- Track the minimum window during the process.

Time Complexity: O(n)
Space Complexity: O(1) (since alphabet size is bounded)
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        
        unordered_map<char, int> need;
        for(char c : t) need[c]++;
        unordered_map<char, int> window;
        int left = 0, right = 0, required = need.size(), formed = 0;
        int minLen = INT_MAX, start = 0;

        while(right < s.size()) {
            window[s[right]]++;
            if(need.count(s[right]) && window[s[right]] == need[s[right]]) formed++;

            while(left <= right && formed == required) {
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                window[s[left]]--;
                if(need.count(s[left]) && window[s[left]] < need[s[left]]) formed--;
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};