class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        vector<int> dp(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            int prev = 0;
            for(int j = 1; j <= n; j++) {
                int temp = dp[j];
                if(s1[i - 1] == s2[j - 1])
                    dp[j] = prev + 1;
                else
                    dp[j] = max(dp[j], dp[j - 1]);
                prev = temp;
            }
        }
        return dp[n];
    }
};