// /*
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// */

// class Solution {
// public:
//     vector<TreeNode*> generateTrees(int n) {
//         if (n == 0) return {};
//         return buildTrees(1, n);
//     }

// private:
//     vector<TreeNode*> buildTrees(int start, int end) {
//         vector<TreeNode*> res;
//         if (start > end) {
//             res.push_back(nullptr);
//             return res;
//         }
//         for (int i = start; i <= end; ++i) 
//         {
//             vector<TreeNode*> leftSubtrees = buildTrees(start, i - 1);
//             vector<TreeNode*> rightSubtrees = buildTrees(i + 1, end);
//             for (TreeNode* left : leftSubtrees) {
//                 for (TreeNode* right : rightSubtrees) 
//                 {
//                     TreeNode* root = new TreeNode(i);
//                     root->left = left;
//                     root->right = right;
//                     res.push_back(root);
//                 }
//             }
//         }
//         return res;
//     }
// };
class Solution {
    map<pair<int, int>, vector<TreeNode*>> memo;

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }

private:
    vector<TreeNode*> buildTrees(int start, int end) {
        if(start > end) 
            return {nullptr};

        if(memo.count({start, end}))
        {
            return memo[{start, end}];
        }
        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) 
        {
            vector<TreeNode*> leftSubtrees = buildTrees(start, i - 1);
            vector<TreeNode*> rightSubtrees = buildTrees(i + 1, end);
            for (TreeNode* left : leftSubtrees) 
            {
                for (TreeNode* right : rightSubtrees) 
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return memo[{start, end}] = res;
    }
};
