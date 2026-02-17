/* Sliding Window
Invarient: The current window always contains atmost 2 distinct numbers.

Approach:
 (use an unordered map for frequency count)
- Expand the window towards right untill the window contains 
  only 2 distinct numbers.
- If the window contains more than 2 distinct number shrink 
  the window till the invarient is satisfied.
- Track the maximum window size that satisfies the invarient.

Time Complexity: O(n)
space Complexity: O(1) //atmost 2 keys in the map
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int left = 0, ans = 0;
        for(int right = 0; right < fruits.size(); right++) {
            freq[fruits[right]]++;
            while(freq.size() > 2) {
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0) freq.erase(fruits[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};