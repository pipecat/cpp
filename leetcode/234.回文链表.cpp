/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        if (head == nullptr)
        {
            return false;
        }
        ListNode* p;
        p = head;
        while (p != nullptr)
        {
            s.push(p->val);
            p = p->next;
        }
        p = head;
        while (!s.empty())
        {
            int last = s.top();
            s.pop();
            if (last != p->val)
            {
                return false;
            }
            p = p->next;
        }
        return true;
        // if (s.size() == 3)
        // {
        //     return true;
        // }
        // return false;
        
    }

};
// @lc code=end

