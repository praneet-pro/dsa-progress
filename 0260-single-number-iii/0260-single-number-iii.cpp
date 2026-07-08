class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;

        for(int num : nums) {
            xor_all ^= num;
        }

        unsigned int probe = xor_all & -(unsigned int)xor_all;
        int bucket_1 = 0, bucket_2 = 0;

        for(int num : nums) {
            if(probe & num) 
                bucket_1 ^= num;
            else
                bucket_2 ^= num;
        }
        return {bucket_1, bucket_2};
    }
};