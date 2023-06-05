#pragma once
// code to be copied to the leetcode page
class LongestIncreasingSubsequence
{
    class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {

            int output[nums.size()];
            fill_n(output, nums.size(), 1);

            int maxLength = 1;

            for (int i = 1; i < nums.size(); i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[i] > nums[j]) {
                        output[i] = max(output[i], output[j] + 1);
                    }

                    maxLength = max(maxLength, output[i]);
                }
            }

            return maxLength;
        }
    };
};

