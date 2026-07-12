class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long sum = 0;
        for(int x : nums) {
            sum += x;
        }

        if(sum <= k) return 0;
        long long balance = sum - k;

        long long total_times = (balance + k - 1)/k;

        // to prevent overflow of A(A + 1)/2

        long long mod = 1000000007;
        long long A = total_times;
        long long B = A + 1;

        if(A & 1) B /= 2;
        else A /= 2;

        A %= mod;
        B %= mod;

        long long total_cost = (A * B) % mod;

        return total_cost;   
    }
};