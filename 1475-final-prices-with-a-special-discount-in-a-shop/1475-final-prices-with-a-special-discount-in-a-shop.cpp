class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        vector<int> res = prices;

        // As there are duplicate elements we store index in Stack
        for(int i = 0; i < prices.size(); i++) {
            while(!st.empty() && prices[i] <= prices[st.top()]) {
                res[st.top()] = prices[st.top()] - prices[i]; 
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};