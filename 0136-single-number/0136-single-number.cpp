/* 
We use XOR logic to remove duplicates
we know A ^ B ^ A = B
The A and A gets cancelled the similar logic is applied here.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;

        for(int x : nums) {
            num ^= x;
        }
        return num;
    }
};