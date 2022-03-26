/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
    const string letter="abcdefghijklmnopqrstuvwxyz";
public:
    vector<string> letterCombinations(string digits) {
        map<string, vector<int>> m;
        m["2"] = {0, 1, 2};
        m["3"] = {3, 4, 5};
        m["4"] = {6, 7, 8};
        m["5"] = {9, 10, 11};
        m["6"] = {12, 13, 14};
        m["7"] = {15, 16, 17, 18};
        m["8"] = {19, 20, 21};
        m["9"] = {22, 23, 24, 25};
        queue<string> result;
        int now=0;
        while (now < digits.size()) {
            string sub=digits.substr(now, 1);
            if (now == 0) {
                for (int i=0; i<m[sub].size(); i++) {
                    result.push(letter.substr(m[sub][i], 1));
                } 
            } 
            else 
            {
                int n=result.size();
                for (int i=0; i<n; i++) {
                    string temp=result.front();
                    result.pop();
                    for (int j=0; j<m[sub].size(); j++) {
                        result.push(temp + letter.substr(m[sub][j], 1));
                    }
                }
                    
            }
            now++;
        }
        vector<string> r;
        for (int i=0; i<result.size(); i++) {
            r.push_back(result.front());
            result.pop();
        }
        return r;
    }
};
// @lc code=end

