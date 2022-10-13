#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    long long maxval;
    TreeNode* left;
    TreeNode* mid;
    TreeNode* right;
    TreeNode(int x): val(x), maxval(0), left(nullptr), mid(nullptr), right(nullptr) {}
};

bool comp(int a, int b) {
    return a > b;
}

void visit(TreeNode* root, long long& result) {
    if (root == nullptr) return;
    vector<long long> tmp;
    if (root->left != nullptr) tmp.push_back(root->left->maxval);
    if (root->mid != nullptr) tmp.push_back(root->mid->maxval);
    if (root->right != nullptr) tmp.push_back(root->right->maxval);
    sort(tmp.begin(), tmp.end(), comp);
    if (!tmp.empty() && tmp[0] < 0) result = max(result, (long long)root->val);
    if (tmp.size() > 1 && tmp[1] > 0) {
        result = max(result, root->maxval + tmp[1]);
    } else {
        result = max(result, root->maxval);
    }
    // cout << root->maxval << ' ';
    // if (root->val > 0) {
    //     long long tmpval = root->val;
    //     if (!tmp.empty() && tmp[0] > 0) tmpval += tmp[0];
    //     if (tmp.size() > 1 && tmp[1] > 0) tmpval += tmp[1];
    //     result = max(result, tmpval);
    // } else {
    //     long long tmpval = 0;
    //     if (!tmp.empty()) tmpval = max(tmpval, tmp[0]);
    //     result = max(result, tmpval); 
    // }
    // result = max(result, (long long)root->val);
    // if (!tmp.empty() && tmp[0] > 0) result = max(result, root->val + tmp) += tmp[0];

    visit(root->left, result);
    visit(root->mid, result);
    visit(root->right, result);
}

int dpvisit(TreeNode* root) {
    if (root == nullptr) return 0;
    root->maxval = max(max(max(dpvisit(root->left), dpvisit(root->mid)), dpvisit(root->right)) + root->val, 0);
    return root->maxval;
}

int main() {
    int n, i=0;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(0);
    q.push(root);
    int val;
    cin >> val;
    root->val = val;
    ++i;
    while (i < n) {
        TreeNode* tmp = q.front();
        if (i < n) {
            cin >> val;
            if (val != -1) {
                tmp->left = new TreeNode(val);
                q.push(tmp->left);
            }
            ++i;
        }
        if (i < n) {
            cin >> val;
            if (val != -1) {
                tmp->mid = new TreeNode(val);
                q.push(tmp->mid);
            }
            ++i;
        }
        if (i < n) {
            cin >> val;
            if (val != -1) {
                tmp->right = new TreeNode(val);
                q.push(tmp->right);
            }
            ++i;
        }
        q.pop();
    }
    dpvisit(root);
    long long result = root->maxval;
    visit(root, result);
    cout << result << endl;
    return 0;
}