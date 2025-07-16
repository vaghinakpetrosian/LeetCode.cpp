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
        // if(!list1)
        //     tmp->next = list2;
        // if(!list2)
        //     tmp->next = list1;
        return res;
    }
};
