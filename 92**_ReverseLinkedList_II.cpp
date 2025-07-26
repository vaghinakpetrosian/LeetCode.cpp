// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
class Solution {
public:
//     ListNode* reverseBetween(ListNode* head, int l, int r) 
//     {
//         if(l == r)
//             return head;
//         int n = 2;
//         if(l == 1)
//         {
//             n = 1;
//             ListNode* right = head;
//             while(n != r)
//             {
//                 right = right->next;
//                 ++n;
//             }  
//             ListNode* tmp = head->next->next;
//             ListNode* cur = head->next;
//             cur->next = head;
//             head->next = right->next;
//             while(cur != right)
//             {
//                 head = cur;
//                 cur = tmp;
//                 tmp = tmp->next;
//                 cur->next = head;
//             }  
//             head = cur;
//             cur = tmp = right = nullptr;
//             return head; 
//         }
//         else{
//             ListNode* tmp = head;
//             while(n != l)
//             {
//                 tmp = tmp->next;
//                 ++n;
//             }  
//             ListNode* right = tmp->next;
//             while(n != r)
//             {
//                 right = right->next;
//                 ++n;
//             }  
//             ListNode *left = tmp->next;
//             ListNode* t = left->next->next;
//             ListNode* cur = left->next;
//             cur->next = left;
//             left->next = right->next;
//             while(cur != right)
//             {
//                 left = cur;
//                 cur = t;
//                 t = t->next;
//                 cur->next = left;
//             }  
//             tmp->next = cur;
//         }
//         return head;
//     }

    ListNode* reverseBetween(ListNode* head, int l, int r) 
    {
        if (!head || l == r) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for (int i = 1; i < l; ++i)
            prev = prev->next;

        ListNode* cur = prev->next;
        for (int i = 0; i < r - l; ++i) {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy.next;
    }
};
