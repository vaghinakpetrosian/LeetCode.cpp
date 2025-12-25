/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    struct Val
    {
        int max;
        int maxch;
        Val(int a, int b) : max {a}, maxch {b}{}
        Val():max{0}, maxch{0}{}
    };
    Val foo(TreeNode* root)
    {
        if(!root)
            return Val(0,0);
        Val left = foo(root->left);
        Val right = foo(root->right);
        Val tmp;
        tmp.maxch = (left.maxch > right.maxch ? left.maxch : right.maxch) + root->val;
        tmp.maxch = (tmp.maxch > root->val ? tmp.maxch : root->val);
        tmp.max = left.maxch + right.maxch + root->val;
        tmp.max = left.max > tmp.max ? left.max : tmp.max;
        tmp.max = right.max > tmp.max ? right.max : tmp.max;
        tmp.max = tmp.max > root->val ? tmp.max : root->val;
        if(tmp.max < tmp.maxch)
            tmp.max = tmp.maxch;
        return tmp;
    }
    int goo(TreeNode* root)
    {
        if(!root)
            return INT_MIN;
        int a = goo(root->right);
        int b = goo(root->left);
        a = (a < root->val ? root->val : a);
        return a < b ? b : a;
    }
public:
    int maxPathSum(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        Val res = foo(root);
        // Val left = foo(root->left);
        // Val right = foo(root->right);
        // int res1 = left.maxch + root->val + right.maxch;
        // // if(root->left)
        // //     res1 += root->left->val;
        // // if(root->right)
        // //     res1 += root->right->val;
        // if(res1 > left.max)
        // {
        //     if(res1 > right.max)
        //         return res1;
        //     else
        //         return right.max;
        // }
        // if(left.max > right.max)
        //     return left.max;
        if(res.max == 0)
        {
            return goo(root);
        }
        if(res.max > res.maxch)
            return res.max;
        return res.maxch;
    }
};
