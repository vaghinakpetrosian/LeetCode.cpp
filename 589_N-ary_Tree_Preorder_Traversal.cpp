/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) 
    {
        if(!root)
        {
            return vector<int>{};
        }    
        stack<Node*> s;
        s.push(root);
        Node* tmp = root;
        vector<int> res;
        while(!s.empty())
        {
            tmp = s.top();
            s.pop();
            res.push_back(tmp->val);
            int n = tmp->children.size();
            for(int i = n - 1; i >= 0; --i)
            {
                s.push(tmp->children[i]);
            }
        }
        return res;
    }
    // vector<int> preorder(Node* root)
    // {
    //     if(!root)
    //         return vector<int>{};
    //     vector<int> res;
    //     res.push_back(root->val);
    //     for(Node* tmp : root->children)
    //     {
    //         dfs(tmp, res);
    //     }
    //     return res;
    // }
    // void dfs(Node* root, vector<int>& res)
    // {
    //     res.push_back(root->val);
    //     for(Node* tmp : root->children)
    //     {
    //         dfs(tmp, res);
    //     }
    // }
};
