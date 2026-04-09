class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low < high) {
            int mid = low + (high - low)/2;
            int hrs = 0;
            for(int i = 0; i < piles.size(); i++) {
                hrs += (piles[i] + mid - 1)/mid;    // instead of ceil
            }
            if(hrs <= h) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};