/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum[nums.size()];
        int result = -1000000;
        for (int i = 0; i < nums.size(); i++)
        {
            sum[i] = -1000000;
        }
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (sum[i-1] + nums[i] > nums[i])   
            {
                sum[i] = sum[i-1] + nums[i];
            }
            else
            {
                sum[i] = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum[i] > result)
            {
                result = sum[i];
            }
            
        }
        return result;
        
    }
};
// @lc code=end

