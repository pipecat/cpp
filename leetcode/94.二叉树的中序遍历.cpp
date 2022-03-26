/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)
        {
            vector<int> root;
            return root;
        }
        vector<int> left_vec=inorderTraversal(root->left);
        vector<int> right_vec=inorderTraversal(root->right);
        
        left_vec.push_back(root->val);
        for (int i = 0; i < right_vec.size(); i++)
        {
            left_vec.push_back(right_vec[i]);
        }
        return left_vec;
        
        
    }
};
// @lc code=end

