class Solution {
public:
    int getRange(int n) {
        int maxDigit = 0, minDigit = 9;

        while(n != 0) {
            int digit = n % 10;
            maxDigit = max(maxDigit, digit);
            minDigit = min(minDigit, digit);
            n /= 10;
        }
        return maxDigit - minDigit;
    }

    int maxDigitRange(vector<int>& nums) {
        int maxRange = 0, sum = 0;

        for(int num : nums) {
            int cur_range = getRange(num);

            if(cur_range > maxRange) {
                maxRange = cur_range;
                sum = num;
            }
            else if(cur_range == maxRange) {
                sum += num;
            }
        }
        return sum;
    }
};