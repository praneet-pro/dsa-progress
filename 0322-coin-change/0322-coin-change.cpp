class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int maxValue = amount + 1;              // if used INT_MAX causes buffer overflow
        vector<int> dp(amount + 1, maxValue);   // amount + 1 acts as fake infinity
        dp[0] = 0;

        for(int i = 1; i <= amount; i++) {
            for(int coin : coins) {
                if(i - coin >= 0)
                    dp[i] = min(dp[i], dp[i - coin] + 1);       // we gave 1 coin and still have to give dp[i - coin] coins
            }                                                   // eg: 11   coin:5  - gave 5 and still have dp[6] rem
        }
        if(dp[amount] == maxValue) return -1;
        return dp[amount];
    }
};