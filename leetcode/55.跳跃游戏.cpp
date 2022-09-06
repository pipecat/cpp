/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> result(nums.size(), false);
        result[0] = true;
        for (int i = 0; i < nums.size(); i++)
        {
            if (result[i])
            {
                // int temp = i + nums[i];
                for (int temp = i+1; temp <= i + nums[i]; temp++)
                    if (temp < nums.size()) result[temp] = true;
            }
            
        }
        return result[nums.size() - 1];
        
    }
};
// @lc code=end

