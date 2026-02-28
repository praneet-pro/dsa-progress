class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, leftMax = 0, right = height.size() - 1, rightMax = 0, totalWater = 0;
        while(right > left) {
            if(height[left] <= height[right]) {
                if(height[left] >= leftMax) 
                    leftMax = height[left];
                else
                    totalWater += leftMax - height[left];
                left++;
            }

            if(height[right] < height[left]) {
                if(height[right] >= rightMax) 
                    rightMax = height[right];
                else
                    totalWater += rightMax - height[right];
                right--;
            }
        }
        return totalWater;
    }
};