/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* next;
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        for (int i = 0; i < 10005; i++)
        {
            head = head->next;
            if (head == nullptr)
            {
                return false;
            }
            
        }
        return true;

        // next = head->next;
        // head->next = nullptr;
        // ListNode* tail=last(next);
        // if (tail == head)
        // {
        //     return true;
        // }
        // head->next = next;
        // return hasCycle(next);
    }
    
    ListNode* last(ListNode *head) {
        while (head->next != nullptr)
        {
            head = head->next;
        }
        return head;
    }
};
// @lc code=end

