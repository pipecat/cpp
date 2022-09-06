#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int th=0, result=0;
        visit(root, th, k, result);
        return result;
    }
    void visit(TreeNode* now, int& th, int k, int& result) {
        if (!now) return;
        visit(now->left, th, k, result);
        th++;
        if (th == k) {
            result = now->val;
        }
        visit(now->right, th, k, result);
    }
};

int main() {
    Solution* solu = new Solution();
    return 0;
}
