#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i = 0;
        ListNode* fakehead = new ListNode(0);
        ListNode* result;
        fakehead->next = head;
        result = fakehead;
        ListNode* last;
        last = fakehead;
        ListNode* p=fakehead->next;
        while (p != nullptr) {
            ListNode* q=p;
            i = 0;
            while ( q != nullptr && i < k) {
                i++;
                q = q->next;
            }
            if (i == k) {
                ListNode* tail = findTail(p);
                // ListNode* v = tail->next;
                tail->next = nullptr;
                tail = reverse(p);
                fakehead->next = tail;
                p->next = q;
                fakehead = p;
                p = q;
            } else {
                break;
            }
        }
        return result->next;
    }
    ListNode* findTail(ListNode* node) {
        while (node->next != nullptr) {
            node = node->next;
        }
        return node;
    }

    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* p = head;
        ListNode* q = p->next;
        ListNode* v = q->next;
        p->next = nullptr;
        while(q != nullptr) {
            q->next = p;
            p = q;
            q = v;
            if (v != nullptr)v = v->next;
        }
        return p;
    }

};

ListNode* vec_to_listnode(vector<int>& vec) {
    ListNode* head = new ListNode();
    ListNode* p = head;
    for (int i = 0; i < vec.size(); i++) {
        p->next = new ListNode(vec[i]);
        p = p->next;
    }
    return head->next;
}

int main() {
    vector<int> vec={};
    Solution* test = new Solution();

    return 0;
}