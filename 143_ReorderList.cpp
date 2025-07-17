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
// private:
//     ListNode* reverseList(ListNode* head) 
//     {
//         if(!head || !head->next)
//             return head;
//         ListNode* tmp = head->next->next;
//         ListNode* cur = head->next;
//         cur->next = head;
//         head->next = nullptr;
//         while(tmp)
//         {
//             head = cur;
//             cur = tmp;
//             tmp = tmp->next;
//             cur->next = head;
//         }    
//         return cur;
//     }
public:
    void reorderList(ListNode* head) 
    {
        if(!head->next || !head->next->next)
        {
            return;
        }   
        ListNode* s = head;
        ListNode* f = head->next;
        while(f->next && f->next->next)
        {
            s = s->next;
            f = f->next->next;
        }
        if(!(!s->next || !s->next->next))
        {
            ListNode* tm = s->next->next->next;
            ListNode* cur = s->next->next;
            cur->next = s->next;
            s->next->next = nullptr;
            while(tm)
            {
                s->next = cur;
                cur = tm;
                tm = tm->next;
                cur->next = s->next;
            } 
            s->next = cur;
        }
        f = head;
        while(f!=s)
        {
            ListNode* tmp = f->next;
            f->next = s->next;
            s->next = s->next->next;
            f->next->next = tmp;
            f = f->next->next;
            //s = s->next;
        }
    }
};
