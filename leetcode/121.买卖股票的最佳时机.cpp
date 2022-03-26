/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minval[prices.size()];
        int result=0;
        minval[0] = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > minval[i-1])
            {
                minval[i] = minval[i-1];
            }
            else
            {
                minval[i] = prices[i];
            }
        }
        
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] - minval[i] > result)
            {
                result = prices[i] - minval[i];
            }
            
        }
        
        return result;
        
    }
};
// @lc code=end

