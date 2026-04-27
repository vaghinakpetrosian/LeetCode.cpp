// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// private:
//     void helper(TreeNode* root, vector<vector<int>>& res)
//     {
        

//     }
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
//     {
//         if(!root)
//         {
//             return vector<vector<int>>{};
//         }
//         std::deque<TreeNode*> dq;
//         dq.push_back(root);
//         vector<vector<int>> res;
//         res.push_back({root->val});
//         bool key = false;
//         int count = 1;
//         while(!dq.empty())
//         {
//             int c = count;
//             count = 0;
//             TreeNode* tmp;
//             vector<int> pairs(size);
//             if(key)
//             {
//                 while(c)
//                 {
//                     tmp = dq.front();
//                     if(tmp->left)
//                     {
//                         pairs.push_back(tmp->left->val);
//                         dq.push_back(tmp->left);
//                         ++count;
//                     }
//                     if(tmp->right)
//                     {
//                         pairs.push_back(tmp->right->val);
//                         dq.push_back(tmp->right);
//                         ++count;
//                     }
//                     dq.pop_front();
//                     --c;
//                 }
//                 key ^= 1;
//             }
//             else
//             {
//                 while(c)
//                 {
//                     tmp = dq.back();
//                     if(tmp->right)
//                     {
//                         pairs.push_back(tmp->right->val);
//                         dq.push_front(tmp->right);
//                         ++count;
//                     }
//                     if(tmp->left)
//                     {
//                         pairs.push_back(tmp->left->val);
//                         dq.push_front(tmp->left);
//                         ++count;
//                     }
//                     dq.pop_back();
//                     --c;
                    
//                 }
//                 key ^= 1;
//             }
//             if(!pairs.empty())
//             {
//                 res.push_back(pairs);
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool key = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                int index = key ? i : (size - 1 - i);
                row[index] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            key ^= 1;
            res.push_back(row);
        }
        return res;
    }
};
