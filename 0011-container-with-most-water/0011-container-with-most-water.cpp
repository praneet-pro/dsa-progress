class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, maxArea = 0, left = 0, right = height.size() - 1;
        while(right > left) {
            int width = right - left;
            area = min(height[left], height[right]) * width;
            maxArea = max(maxArea, area);
            if(height[right] > height[left]) left++;
            else right--;
        }
        return maxArea;
    }
};