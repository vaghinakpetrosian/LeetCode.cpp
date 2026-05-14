class Solution {
private:
    int get_depth(TreeNode* root) {
        if (!root) return 0;
        return std::max(get_depth(root->left), get_depth(root->right)) + 1;
    }

    void locate(vector<vector<string>>& res, TreeNode* root, int r, int c, int m) {
        if (!root) return;
        
        res[r][c] = std::to_string(root->val);
        
        if (r < m - 1) {
            int offset = 1 << (m - r - 2); 
            locate(res, root->left, r + 1, c - offset, m);
            locate(res, root->right, r + 1, c + offset, m);
        }
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        int m = get_depth(root);
        int n = (1 << m) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        locate(res, root, 0, (n - 1) / 2, m);
        return res;
    }
};
