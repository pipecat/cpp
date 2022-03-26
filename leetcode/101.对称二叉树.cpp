/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> queue1,queue2;
        int i=0;
        
        if (root == nullptr)
        {
            return true;
        }
        queue1.push_back(root);
        queue2.push_back(root);

        while (i < queue1.size())
        {

            if (queue1[i]->val != queue2[i]->val)
            {
                return false;
            }


            if (queue2[i]->right != nullptr && queue1[i]->left != nullptr)
            {
                queue1.push_back(queue1[i]->left);
                queue2.push_back(queue2[i]->right);
            }
            else if (queue2[i]->right != nullptr || queue1[i]->left != nullptr)
            {
                return false;
            }

            if (queue2[i]->left != nullptr && queue1[i]->right != nullptr)
            {
                queue1.push_back(queue1[i]->right);
                queue2.push_back(queue2[i]->left);
            }
            else if (queue2[i]->left != nullptr || queue1[i]->right != nullptr)
            {
                return false;
            }

            i++;
        }
        return true;
    }
};
// @lc code=end

