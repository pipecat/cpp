/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (unsigned int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0 )
            {
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                // i--;
            }
            
        }
        
        
    }
};
// @lc code=end

