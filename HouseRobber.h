#pragma once
// code to be copied to the leetcode page
class HouseRobber
{
    class Solution {
    public:
        int rob(vector<int>& nums) {
            if (nums.size() == 1) return nums[0];
            if (nums.size() == 2) return max(nums[0], nums[1]);

            int* arr = new int[nums.size() + 1];
            arr[0] = 0;
            arr[1] = nums[0];

            for (int i = 2; i <= nums.size(); i++)
                arr[i] = max(arr[i - 1], arr[i - 2] + nums[i - 1]);

            int result = arr[nums.size()];
            return result;
        }
    };
};