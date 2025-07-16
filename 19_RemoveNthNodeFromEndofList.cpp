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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* f = head;
        while(n)
        {
            --n;
            f = f->next;
        }   
        ListNode* s = head, *tmp = nullptr; 
        while(f)
        {
            tmp = s;
            s = s->next;
            f = f->next;
        }
        if(!tmp)
        {
            head = s->next;
        }
        else{
            tmp->next = tmp->next->next;
        }
        delete s;
        return head;
    }
};
