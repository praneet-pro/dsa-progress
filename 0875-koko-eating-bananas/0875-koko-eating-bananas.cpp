class Solution {
public:

    bool is_pos(vector<int>& piles, int h, int k) {
        long long hrs = 0;
        for(int i = 0; i < piles.size(); i++) {
            hrs += (piles[i] + k - 1) / k;
        }
        return h >= hrs;
    } 

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high) {
            int mid = low + (high - low)/2;

            if(is_pos(piles, h, mid))
                high = mid;

            else
                low = mid + 1;
        }
        return low;
    }
};