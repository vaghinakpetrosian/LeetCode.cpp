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
// public:
//     bool isValidBST(TreeNode* root) 
//     {
//         long long b;
//         long long a = LLONG_MIN;
//         stack<TreeNode*> s;
//         TreeNode* tmp = root;
//         while (tmp || !s.empty()) 
//         {
//             while (tmp) 
//             {
//                 s.push(tmp);
//                 tmp = tmp->left;
//             }
//             tmp = s.top();
//             b = a;
//             a = tmp->val; 
//             if(a <= b)
//             {
//                 return false;
//             }
//             s.pop();
//             tmp = tmp->right;
//         }    
//         return true;
//     }
// };
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
    }
private:
    bool valid(TreeNode* node, long long left, long long right) {
        if (!node) {
            return true;
        }
        if (!(node->val < right && node->val > left)) {
            return false;
        }
        return valid(node->left, left, node->val) && 
               valid(node->right, node->val, right);
    }
};
