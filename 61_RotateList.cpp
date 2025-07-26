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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head)
        {
            return head;
        }
        ListNode* tmp = head;
        int n = 1;
        while(tmp->next)
        {
            tmp = tmp->next;
            ++n;
        }
        k %= n;
        n -= k;
        --n;
        ListNode* t = head;
        while(n)
        {
            t = t->next;
            --n;
        }
        tmp->next = head;
        head = t->next;
        t->next = nullptr;
        return head;
    }
};
