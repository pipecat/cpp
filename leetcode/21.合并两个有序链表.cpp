/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 迭代法
        // 
        // ListNode* p1;
        // p1 = new ListNode();
        // ListNode* p2 = p1;
        // while (l1 != nullptr && l2 != nullptr)
        // {
        //     if (l1->val < l2->val)
        //     {
        //         ListNode* p=new ListNode(l1->val);
        //         p2->next = p;
        //         p2 = p2->next;
        //         l1 = l1->next;
        //     }
        //     else
        //     {
        //         ListNode* p=new ListNode(l2->val);
        //         p2->next = p;
        //         p2 = p2->next;
        //         l2 = l2->next;
        //     }
        // }
        // if (l1 == nullptr)
        // {
        //     p2->next = l2;
        // }
        // if (l2 == nullptr)
        // {
        //     p2->next = l1;
        // }
        // return p1->next;

        // 递归法
        // 
        ListNode* p=new ListNode();
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }
        if (l1->val < l2->val)
        {
            ListNode* p=new ListNode(l1->val, mergeTwoLists(l1->next, l2));
            return p;
        }
        else
        {
            ListNode* p=new ListNode(l2->val, mergeTwoLists(l1, l2->next));
            return p;
        }
    }
};
// @lc code=end

