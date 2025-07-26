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
    // ListNode* reverseList(ListNode* head) 
    // {
    //     if(!head || !head->next)
    //         return head;
    //     ListNode* tmp = head->next->next;
    //     ListNode* cur = head->next;
    //     cur->next = head;
    //     head->next = nullptr;
    //     while(tmp)
    //     {
    //         head = cur;
    //         cur = tmp;
    //         tmp = tmp->next;
    //         cur->next = head;
    //     }    
    //     return cur;
    // }
    // bool isPalindrome(ListNode* head)
    // {   
    //     if(!head->next)
    //         return true;
    //     ListNode* s = head;
    //     ListNode* f = head->next;
    //     while(f->next && f->next->next)
    //     {
    //         f = f->next->next;
    //         s = s->next;
    //     }
    //     ListNode* h = s->next->next;
    //     s->next = nullptr;
    //     s = reverseList(s);
    //     while(s)
    //     {
    //         if(s->val != h->val)
    //             return false;
    //         s = s->next;
    //         h = h->next;
    //     }
    //     return true;
    // }
    //--------------------------------------------
    // bool isPalindrome(ListNode* head) 
    // {
    //     vector<short> h1;
    //     ListNode* tmp = head;
    //     while(tmp)
    //     {
    //         h1.push_back(tmp->val);
    //         tmp = tmp->next;
    //     }
    //     ListNode* h2 = reverseList(head);
    //     int i = 0;
    //     while(h2)
    //     {
    //         if(h1[i] != h2->val)
    //             return false;
    //         ++i;
    //         h2 = h2->next;
    //     }
    //     return true;
    // }
    //--------------------------------------------
    bool isPalindrome(ListNode* head)
    {   
        if(!head->next)
            return true;
        if(!head->next->next)
        {
            if(head->val == head->next->val)
                return true;
            return false;
        }
        ListNode* s = head;
        ListNode* f = head->next->next;
        ListNode* tmp = head->next->next;
        ListNode* cur = head->next;
        cur->next = s;
        s->next = nullptr;
        while(f->next && f->next->next)
        {
            f = f->next->next;
            s = cur;
            cur = tmp;
            tmp = tmp->next;
            cur->next = s;
        }
        if(!f->next)
            cur = cur->next;
        while(cur)
        {
            if(cur->val != tmp->val)
                return false;
            cur = cur->next;
            tmp = tmp->next;
        }
        return true;
    }
};
