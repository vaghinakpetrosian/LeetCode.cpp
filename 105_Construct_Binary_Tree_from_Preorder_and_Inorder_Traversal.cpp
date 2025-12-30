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
// class Solution {
//     TreeNode* help(vector<int>& preorder, vector<int>& inorder, int s, int e, int& rut)
//     {
//         if(s > e)
//         {
//             return nullptr;
//         }
//         TreeNode* root = new TreeNode(preorder[rut]);
//         for(int i = s; i <= e; ++i)
//         {
//             if(inorder[i] == preorder[rut])
//             {
//                 if(s <= i - 1)
//                 {
//                     ++rut;
//                     root->left = help(preorder, inorder, s, i - 1, rut);
//                 }
//                 else
//                 {
//                     root->left = nullptr;
//                 }
//                 if(e >= i + 1)
//                 {
//                     ++rut;
//                     root->right = help(preorder, inorder, i + 1, e, rut);
//                 }
//                 else
//                     root->right = nullptr;
//                 break;
//             }
//         }
//         return root;
//     } 
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
//     {
//         int rut = 0;
//         return help(preorder, inorder, 0, preorder.size() - 1, rut);
//     }
// };

class Solution 
{
    unordered_map<int,int> pos;
    TreeNode* help(vector<int>& preorder, int s, int e, int& rut)
    {
        if (s > e) return nullptr;
        TreeNode* root = new TreeNode(preorder[rut]);
        int i = pos[preorder[rut]];
        ++rut;
        root->left = help(preorder, s, i - 1, rut);
        root->right = help(preorder, i + 1, e, rut);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
            pos[inorder[i]] = i;
        int rut = 0;
        return help(preorder, 0, inorder.size() - 1, rut);
    }
};
