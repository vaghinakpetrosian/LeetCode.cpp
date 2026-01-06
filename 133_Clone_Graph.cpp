/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* vis[101] = {nullptr};
    Node* dfs(Node* node) 
    {
        if(!node) 
            return nullptr;
        if(vis[node->val])
            return vis[node->val];
        Node* copy = new Node(node->val);
        vis[node->val] = copy;
        for (Node* neigh : node->neighbors) 
        {
            copy->neighbors.push_back(dfs(neigh));
        }
        return copy;
    }

public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
