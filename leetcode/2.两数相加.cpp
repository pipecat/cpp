/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode* head = new ListNode();
        ListNode *h1, *h2, *h;
        h = head;
        h1 = l1;
        h2 = l2;
        while (l1 != nullptr || l2 != nullptr)
        {
            
            int val1, val2, result;
            if (l1 == nullptr)
            {
                val1 = 0;
            }
            else
            {
                val1 = l1->val;
            }

            if (l2 == nullptr)
            {
                val2 = 0;
            }
            else
            {
                val2 = l2->val;
            }
            result = val1 + val2 + c;
            h->next = new ListNode(result % 10);
            c = result / 10;
            h = h->next;
            if (l1 != nullptr)
            {
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                l2 = l2->next;
            }
            

        }
        if (c != 0)
        {
            h->next = new ListNode(c);
        }
        
        return head->next;
    }
};
// @lc code=end

