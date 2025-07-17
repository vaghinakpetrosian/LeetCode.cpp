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
    bool hasCycle(ListNode *head) 
    {
        if(!head)
            return false;
        ListNode* s, *f;
        if(head->next)
            s = head->next;
        else return false;
        if(head->next->next)
            f = head->next->next;
        else return false;
        while(f && f->next)
        {
            if(s == f)
                return true;
            s = s->next;
            f = f->next->next;
        }   
        return false; 
    }
};
