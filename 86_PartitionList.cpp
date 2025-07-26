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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *h1 = nullptr, *h2 = nullptr;
        ListNode* c1 = nullptr, *c2 = c1;
        while(head)
        {
            if(x <= head->val)
            {
                if(!h1)
                {
                    h1 = new ListNode(head->val);
                    c1 = h1;
                    head = head->next;
                    continue;
                }
                h1->next = new ListNode(head->val);
                h1 = h1->next;
            }
            else
            {
                if(!h2)
                {
                    h2 = new ListNode(head->val);
                    c2 = h2;
                    head = head->next;
                    continue;
                }
                h2->next = new ListNode(head->val);
                h2 = h2->next;
            }
            head = head->next;
        }
        if(h2)
            h2->next = c1;
        else
            return c1;
        return c2;
    }
};
