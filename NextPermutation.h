#pragma once
// code to be copied to the leetcode page
class NextPermutation
{
    #include <vector>
    #include <algorithm>

    class Solution {
    public:
        void nextPermutation(std::vector<int>& nums) {
            int n = nums.size();
            int i = n - 2;

            while (i >= 0 && nums[i] >= nums[i + 1]) {
                i--;
            }

            if (i >= 0) {
                int j = n - 1;
                while (j > i && nums[j] <= nums[i]) {
                    j--;
                }

                std::swap(nums[i], nums[j]);
            }

            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                std::swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
    };
};

