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
private:
    TreeNode* helper(vector<int>& nums, short start, short end)
    {
        if(start >= end)
            return nullptr;
        short index = start;
        for(short i = start + 1; i < end; ++i)
        {
            if(nums[index] < nums[i])
            {
                index = i;
            }
        }
        TreeNode* root = new TreeNode(nums[index]);
        root->right = helper(nums, index + 1, end);
        root->left = helper(nums, start, index);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return helper(nums, 0, nums.size());    
    }
};
