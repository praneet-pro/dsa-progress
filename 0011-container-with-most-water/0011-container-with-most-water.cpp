class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN, left = 0, right = height.size() - 1;
        while(left < right) {
            int width = right - left;
            int area = width * min(height[left], height[right]);
            maxArea = max(maxArea, area);
            if(height[left] > height[right]) right--;
            else left++;
        }
        return maxArea;
    }
};