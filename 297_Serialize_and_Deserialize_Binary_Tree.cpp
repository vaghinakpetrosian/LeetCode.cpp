/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if(node) {
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                res += "n,";
            }
        }
        while(res.size() >= 2 && res.substr(res.size()-2) == "n,") {
            res.erase(res.size()-2);
        }
        if(!res.empty() && res.back() == ',') res.pop_back();
        return res;
    }
    TreeNode* deserialize(string data) 
    {
        if(data.empty()) return nullptr;
        int i = 0, j = 0;
        int n = data.size();
        j = data.find(',', i);
        string val = (j == string::npos) ? data.substr(i) : data.substr(i, j - i);
        TreeNode* root = new TreeNode(stoi(val));
        i = (j == string::npos) ? n : j + 1;
        queue<TreeNode*> node;
        node.push(root);
        while(i < n)
        {
            TreeNode* parent = node.front();
            node.pop();
            j = data.find(',', i);
            val = (j == string::npos) ? data.substr(i) : data.substr(i, j - i);
            TreeNode* tmp = nullptr;
            if(val != "n") {
                tmp = new TreeNode(stoi(val));
                parent->left = tmp;
                node.push(tmp);
            }
            i = (j == string::npos) ? n : j + 1;
            if(i >= n) break;
            j = data.find(',', i);
            val = (j == string::npos) ? data.substr(i) : data.substr(i, j - i);
            tmp = nullptr;
            if(val != "n") {
                tmp = new TreeNode(stoi(val));
                parent->right = tmp;
                node.push(tmp);
            }
            i = (j == string::npos) ? n : j + 1;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
