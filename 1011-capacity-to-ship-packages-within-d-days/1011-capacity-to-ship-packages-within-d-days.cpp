class Solution {
public:
    int isPossible(vector<int>& weights, int capacity) {
        int days = 1, sum = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(sum + weights[i] > capacity) {
                days++;
                sum = weights[i];
            }
            else sum += weights[i];
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low < high) {
            int mid = low + (high - low)/2;
            if(isPossible(weights, mid) <= days) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};