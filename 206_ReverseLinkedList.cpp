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
    ListNode* reverseList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        ListNode* tmp = head->next->next;
        ListNode* cur = head->next;
        cur->next = head;
        head->next = nullptr;
        while(tmp)
        {
            head = cur;
            cur = tmp;
            tmp = tmp->next;
            cur->next = head;
        }    
        return cur;
    }
};
