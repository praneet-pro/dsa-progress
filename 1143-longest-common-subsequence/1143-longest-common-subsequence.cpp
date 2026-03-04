/*
Dynamic Programming

Approach : 
- Used 2D array to store the count with the 1st row and coloumn being empty.
- Empty row and coloumn represented as 0 gives a correct base conditin
  for mathematical base condition.

Optimization: 
- Optimized the storage from O(n * m) to O(n).
- Prev stores the diagonal element value.
- Temp stores the prev rows diagonal value before it is overwritten.

Time Complexity: O(n * m)
Space Complexity: O(n)  (optimized)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        if(m < n) 
            return longestCommonSubsequence(text2, text1);
        vector<int> dp(n + 1, 0);

        for(int i = 1; i <= m; i++) {
            int prev = 0;
            for(int j = 1; j <= n; j++) {
                int temp = dp[j];
                if(text1[i - 1] == text2[j - 1]) 
                    dp[j] = prev + 1;
                else 
                    dp[j] = max(dp[j], dp[j - 1]);
                prev = temp;
            }
        }
        return dp[n];
    }
};