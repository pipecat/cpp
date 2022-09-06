#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r) {
        if (pre_l > pre_r) return nullptr;
        TreeNode* root = new TreeNode(preorder[pre_l]);
        if (pre_l == pre_r) return root;
        int in_index;
        for (int i=in_l; i<=in_r; i++) {
            if (inorder[i] == preorder[pre_l]) in_index = i;
        }
        root->left = build(preorder, inorder, pre_l+1, in_index-in_l+pre_l, in_l, in_index-1);
        root->right = build(preorder, inorder, in_index-in_l+pre_l+1, pre_r, in_index+1, in_r);
        return root;
    }
};

int main() {
    vector<int> preorder = {1,2,3};
    vector<int> inorder = {3,2,1};
    Solution* solu = new Solution;
    TreeNode* p = solu->buildTree(preorder, inorder);
    return 0;
}