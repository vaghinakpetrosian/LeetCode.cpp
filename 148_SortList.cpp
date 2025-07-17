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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* res = nullptr, *tmp = nullptr;
        if(list1->val > list2->val)
        {
            res = list2;
        }
        else{
            res = list1;
        }
        bool v = false;
        while(list1 && list2)
        {
            while(list2 && list1->val > list2->val)
            {
                v = true;
                tmp = list2;
                list2 = list2->next;
            }
            if(v)
            {
                tmp->next = list1;
                v = false;
                continue;
            }
            while(list1 && list1->val <= list2->val)
            {
                v = true;
                tmp = list1;
                list1 = list1->next;
            }
            if(v)
            {
                tmp->next = list2;
                v = false;
            }
        }
        return res;
    }
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* s = head;
        ListNode* f = head;
        if(head)
            f = head->next;
        while(f && f->next)
        {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
public:
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next) 
            return head;
        ListNode* mid = middleNode(head);
        ListNode* head2 = mid->next;
        mid->next = nullptr;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(head2);
        return mergeTwoLists(l1, l2);
    }
};
