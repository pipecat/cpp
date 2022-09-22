#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int id;
    TreeNode* child;
    TreeNode* bro;
    TreeNode(int i): id(i), child(nullptr), bro(nullptr) {}
};

void add(TreeNode* father, TreeNode* child) {
    TreeNode* p = father->child;
    if (p == nullptr) {
        father->child = child;
    } else {
        while (p->bro != nullptr) p = p->bro;
        p->bro = child;
    }
}

// void visit(TreeNode* root, int& result) {
//     TreeNode* ch = root->child;
//     if (ch == nullptr) return;
//     else {
//         while (ch != nullptr) {
//             if (ch->id % 2 == root->id % 2) visit(ch, result);
//             else {
//                 result++;
//                 visit(ch, result);
//             }
//             ch = ch->bro;
//         }
//     }
// }

void visit(TreeNode * root) {
    cout << root->id;
    TreeNode* p = root->child;
    while (p != nullptr)
    {
        cout << p->id;
        p = p->bro;
    }
}

int main() {
    int n, x;
    unordered_map<int, TreeNode*> m;
    int result=0;
    cin >> n >> x;
    for (int i=0; i<n-1; i++) {
        int id, father;
        cin >> id >> father;
        if (!m.count(id)) {
            TreeNode* p = new TreeNode(id);
            m[id] = p;
        }
        if (!m.count(father)) {
            TreeNode* p = new TreeNode(father);
            m[father] = p;
        }
        TreeNode* ch = m[id];
        TreeNode* fa = m[father];
        add(fa, ch);
    }
    visit(m[4]);
    cout << result << endl;
}
