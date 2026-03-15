class Solution {
// private:
//     bool hasCycle(short node, unordered_map<short, vector<short>>& adj, unordered_map<short, short>& state) {
//         if (state[node] == 1) return true;
//         if (state[node] == 2) return false;
//         state[node] = 1;
//         for (short n : adj[node]) {
//             if (hasCycle(n, adj, state)) {
//                 return true;
//             }
//         }
//         state[node] = 2;
//         return false;
//     }
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<short, vector<short>> adj;
//         for (const auto& pre : prerequisites) {
//             adj[pre[1]].push_back(pre[0]);
//         }
//         unordered_map<short, short> state;
//         for (int i = 0; i < numCourses; ++i) {
//             if (state[i] == 0) {
//                 if (hasCycle(i, adj, state)) {
//                     return false;
//                 }
//             }
//         }
//         return true; 
//     }
// Kahn's algorithm
public:
    bool canFinish(int n, vector<vector<int>>& pre)
    {
        vector<vector<short>> adj(n);
        vector<short> ast(n, 0);
        for(const auto& p : pre)
        {
            adj[p[1]].push_back(p[0]);
            ++ast[p[0]];
        }
        queue<short> q;
        for(short i = 0; i < n; ++i)
        {
            if(!ast[i])
            {
                q.push(i);
            }
        }
        short count = 0;
        while(!q.empty())
        {
            short tmp = q.front();
            q.pop();
            short size = adj[tmp].size();
            for(short i = 0; i < size; ++i)
            {
                if(!(--ast[adj[tmp][i]]))
                {
                    q.push(adj[tmp][i]);
                }
            }
            ++count;
        }
    return count == n;
    }
};
