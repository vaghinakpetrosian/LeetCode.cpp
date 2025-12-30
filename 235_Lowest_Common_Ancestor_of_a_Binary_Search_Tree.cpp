/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* tmp = root;
        while(tmp)
        {
            if(p->val < tmp->val && q->val < tmp->val)
            {
                tmp = tmp->left;
            }
            else
            {
                if(p->val > tmp->val && q->val > tmp->val)
                {
                    tmp = tmp->right;
                }
                else
                    return tmp;
            }
        }    
        return tmp;
    }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    // {
    //     std::vector<bool> a, b;
    //     TreeNode* tmp = root;
    //     int m = p->val, n = q->val;
    //     while(tmp)
    //     {
    //         if(tmp->val == m)
    //         {
    //             break;
    //         }
    //         else
    //         {
    //             if(tmp->val > m)
    //             {
    //                 tmp = tmp->left;
    //                 a.push_back(false);
    //             }
    //             else
    //             {
    //                 if(tmp->val < m)
    //                 {
    //                     tmp = tmp->right;
    //                     a.push_back(true);
    //                 }
    //             }
    //         }
    //     }
    //     tmp = root;
    //     while(tmp)
    //     {
    //         if(tmp->val == n)
    //         {
    //             break;
    //         }
    //         else
    //         {
    //             if(tmp->val > n)
    //             {
    //                 tmp = tmp->left;
    //                 b.push_back(false);
    //             }
    //             else
    //             {
    //                 if(tmp->val < n)
    //                 {
    //                     tmp = tmp->right;
    //                     b.push_back(true);
    //                 }
    //             }
    //         }
    //     }
    //     tmp = root;
    //     n = a.size() > b.size() ? b.size() : a.size();
    //     for(int i = 0; i < n; ++i)
    //     {
    //         if(a[i] == b[i])
    //         {
    //             if(a[i])
    //             {
    //                 tmp = tmp->right;
    //             }
    //             else
    //                 tmp = tmp->left;
    //         }
    //         else break;
    //     }
    //     return tmp;
    // }
};
