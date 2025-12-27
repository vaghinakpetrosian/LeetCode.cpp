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
    bool dfs(TreeNode* r, TreeNode* s)
    {
        if(!r || !s)
        {
            if(!s && !r)
            {
                return true;
            }
            return false;
        } 
        if(r->val != s->val)
            return false;
        return dfs(r->right, s->right) && dfs(r->left, s->left);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(!root || !subRoot)
        {
            if(!subRoot && !root)
            {
                return true;
            }
            return false;
        }    
        bool tmp = false;
        if(root->val == subRoot->val)
        {
            tmp = dfs(root->left, subRoot->left) && dfs(root->right, subRoot->right);
        }
        return tmp || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
