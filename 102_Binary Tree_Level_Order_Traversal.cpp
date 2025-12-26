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
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(!root)
            return vector<vector<int>>{};
        std::queue<TreeNode*> tmp{};
        tmp.push(root);
        short level = 0;
        std::vector<vector<int>> res;
        while(!tmp.empty())
        {
            short size = tmp.size();
            res.push_back(std::vector<int>(size, 0));
            while(size)
            {
            TreeNode* a = tmp.front();
                tmp.pop();
                if(a->right)
                {
                    tmp.push(a->right);
                }
                if(a->left)
                {
                    tmp.push(a->left);
                }
                res[level][size - 1] = a->val;
                --size;
            }
            ++level;
        }
        return res;
    }
};
