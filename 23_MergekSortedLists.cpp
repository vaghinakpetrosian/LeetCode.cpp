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
        list1 = list2 = nullptr;
        return res;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size() == 0)
        {
            return nullptr;
        }
        if(lists.size() == 1)
            return lists[0];
        else{
            if(lists.size() == 2)
            {
                return mergeTwoLists(lists[0], lists[1]);
            }
        }
        int size = lists.size();
        for(int i = 0; i < size - 1; i += 2)
        {
            lists[i / 2] = mergeTwoLists(lists[i], lists[i + 1]);
        }  
        if(size % 2 == 1)
        {
            lists[size / 2] = lists[size - 1];
        }
        for(int i = 0; i < size / 2; ++i)
        {
            lists.pop_back();
        }
        return mergeKLists(lists);
    }
};
