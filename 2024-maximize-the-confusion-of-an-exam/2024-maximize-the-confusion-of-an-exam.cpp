/* Sliding Window

Invarient: In the current window the number of character that
           must be flipped (window size - max frequency of 'T' or 'F')
           is atmost k.
        
Approach: 
- Expand the window using the right pointer.
- Track the frequency of 'T' & 'F'.
- If required flip exceeds k, shrink the window from left.
- Track the maximum valid window size.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 0, ans = 0, countT = 0, countF = 0, max_freq = 0;
        for(int right = 0; right < answerKey.length(); right++) {
            if(answerKey[right] == 'T') countT++;
            else countF++;
            max_freq = max(countT, countF);
            while((right - left + 1) - max_freq > k) {
                if(answerKey[left] == 'T') countT--;
                else countF--;
                left++; 
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};