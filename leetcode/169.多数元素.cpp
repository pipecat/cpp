/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        map<int, int>::iterator l_it;

        for (int i = 0; i < nums.size(); i++)
        {
            l_it = m.find(nums[i]);
            if (l_it == m.end())
            {
                m.insert(pair <int, int>(nums[i], 1));
            }
            else
            {
                m[nums[i]]++;
            }
        }
        int result, max=0;
        map <int, int>::iterator it;
        map <int, int>::iterator itend;
        it = m.begin();
        itend = m.end();    
        while (it != itend)
        {
            if (it->second > max)
            {
                max = it->second;
                result = it->first;
            }
            it++;
        }
        return result;
        
    }
};
// @lc code=end

