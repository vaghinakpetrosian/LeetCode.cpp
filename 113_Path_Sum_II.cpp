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
    vector<vector<int>> res;
    vector<int> tar;
    void findPaths(TreeNode* root, int sum) 
    {
        if(!root) 
            return;
        tar.push_back(root->val);
        if(!root->left && !root->right && root->val == sum) 
        {
            res.push_back(tar);
        }
        else{
            findPaths(root->left, sum - root->val);
            findPaths(root->right, sum - root->val);
        }
        tar.pop_back(); 
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
        {
            return false;
        }    
        tar.push_back(root->val);
        if(root->val == targetSum && !root->right && !root->left)
        {
            res.push_back(tar);
            tar.pop_back();
            return true;
        }
        bool tmp = false;
        if(hasPathSum(root->left, targetSum - root->val))
        {
            tmp = true;
        }
        if(hasPathSum(root->right, targetSum - root->val))
        {
            tmp = true;
        }
        tar.pop_back();
        return tmp;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        findPaths(root, targetSum);
        return res;
    }
    // vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    //     if (!root) 
    //         return res;
    //     stack<TreeNode*> s;
    //     TreeNode* curr = root;
    //     TreeNode* prev = nullptr;
    //     long long currentSum = 0;
    //     while (curr || !s.empty()) {
    //         while (curr) {
    //             s.push(curr);
    //             tar.push_back(curr->val);
    //             currentSum += curr->val;
    //             curr = curr->left;
    //         }
    //         curr = s.top();
    //         if (curr->right && curr->right != prev) {
    //             curr = curr->right;
    //         } else {
    //             if (!curr->left && !curr->right && currentSum == targetSum) {
    //                 res.push_back(tar);
    //             }
    //             s.pop();
    //             currentSum -= curr->val;
    //             tar.pop_back();
    //             prev = curr;
    //             curr = nullptr;
    //         }
    //     }
    //     return res;
    // }
};
