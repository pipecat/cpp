/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        int maxnow=1, i=1;
        result.push_back(0);
        while (result.size()<=n)
        {
            if (i==maxnow*2)
            {
                result.push_back(1);
                maxnow = maxnow*2;
            }
            else
            {
                result.push_back(1+result[i-maxnow]);
            }
            i++; 
            
        }
        return result;
    }
};
// @lc code=end

