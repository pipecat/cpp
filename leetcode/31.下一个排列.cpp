/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return ;
        }
        
        int n=nums.size();
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i+1])
            {
                int pos=n-1;
                for (int j = n-1; j > i; j--)
                {
                    if (nums[j] > nums[i])
                    {
                        pos = j;
                        break;
                    }
                }
                swap(nums[i], nums[pos]);
                sort(nums.begin()+i+1, nums.end());
                return ;
            }
        }   
        sort(nums.begin(), nums.end());
    }
    static bool bigger(int i, int j) {
        return i > j;
    }

};
// @lc code=end

