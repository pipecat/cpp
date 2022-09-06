#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    int index;
    TreeNode* child;
    TreeNode* next;
    TreeNode(int _val): val(_val), index(-1), child(nullptr), next(nullptr) {}
};

void add_child(TreeNode* root, TreeNode* p) {
    if (root->child == nullptr) {
        root->child = p;
    } else {
        TreeNode* last=root->child;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = p;
    }
}

unordered_set<int> num(TreeNode* root, vector<int>& result) {
    unordered_set<int> s;
    if (root == nullptr) return s;
    TreeNode* child = root->child;
    while (child != nullptr) {
        unordered_set<int> cs;
        cs = num(child, result);
        s.insert(cs.begin(), cs.end());
        child = child->next;
    }
    s.insert(root->val);
    result[root->index] = s.size();
    return s;
}

int main() {
    int n;
    cin >> n;
    vector<int> father(n, -1);
    vector<TreeNode*> nodes(n, nullptr);
    vector<int> result(n, 0);
    string temp;
    vector<int> ch(n, 0);
    for (int i=1; i<n; i++) {
        cin >> father[i];
    }
    cin >> temp;
    for (int i=0; i<n; i++) {
        ch[i] = temp[i];
        nodes[i] = new TreeNode(ch[i]);
        nodes[i]->index = i;
    }
    for (int i=1; i<n; i++) {
        add_child(nodes[father[i]-1], nodes[i]);
    }
    unordered_set<int> s;
    s = num(nodes[0], result);
    for (int i=0; i<n; i++) {
        if (i == 0) {
            cout << result[i];
        } else {
            cout << ' ' << result[i];
        }
    }
    cout << endl;
    return 0;
}