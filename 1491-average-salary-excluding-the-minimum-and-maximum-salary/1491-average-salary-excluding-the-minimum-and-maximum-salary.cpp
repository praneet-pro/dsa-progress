class Solution {
public:
    double average(vector<int>& salary) {
        int min = *min_element(salary.begin(), salary.end());
        int max = *max_element(salary.begin(), salary.end());

        double total = accumulate(salary.begin(), salary.end(), 0);
        total = total - max - min;
        int n = salary.size() - 2;

        return (double)total / n;
    }
};