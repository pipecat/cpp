/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<TreeNode*> queue1,queue2;
        int i=0;
        
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p == nullptr || q == nullptr)
        {
            return false;
        }

        queue1.push_back(p);
        queue2.push_back(q);

        while (i < queue1.size())
        {

            if (queue1[i]->val != queue2[i]->val)
            {
                return false;
            }


            if (queue2[i]->left != nullptr && queue1[i]->left != nullptr)
            {
                queue1.push_back(queue1[i]->left);
                queue2.push_back(queue2[i]->left);
            }
            else if (queue2[i]->left != nullptr || queue1[i]->left != nullptr)
            {
                return false;
            }

            if (queue2[i]->right != nullptr && queue1[i]->right != nullptr)
            {
                queue1.push_back(queue1[i]->right);
                queue2.push_back(queue2[i]->right);
            }
            else if (queue2[i]->right != nullptr || queue1[i]->right != nullptr)
            {
                return false;
            }

            i++;
        }
        return true;
        
    }
};
// @lc code=end

