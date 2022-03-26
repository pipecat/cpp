/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result, l, r, n;
        unordered_set<char> cc;
        n = s.size();
        result = 0;
        l = -1;
        r = 0;
        for (int i = 0; i < n; i++)
        {
            if (l >= 0)
            {
                cc.erase(s[l]);
            }
            l++;
            if (l >= n)
            {
                break;
            }
            while (r < n)
            {
                if (cc.count(s[r]) > 0)
                {
                    break;
                }
                else
                {
                    cc.insert(s[r]);
                    r++;
                }
            }
            result = max(result, r-l);    
        }  
        return result;      
    }
};
// @lc code=end

