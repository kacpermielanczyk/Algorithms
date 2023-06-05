#pragma once
// code to be copied to the leetcode page
class ContainerWithMostWater
{
    #include <vector>
    #include <algorithm>

    class Solution {
    public:
        int maxArea(std::vector<int>& height) {
            int maxArea = 0;
            int left = 0;
            int right = height.size() - 1;

            int h = 0;
            int w = 0;
            int area = 0;

            while (left < right) {
                h = std::min(height[left], height[right]);
                w = right - left;
                area = h * w;
                maxArea = std::max(maxArea, area);

                if (height[left] < height[right]) {
                    left++;
                }
                else {
                    right--;
                }
            }

            return maxArea;
        }
    };
};

