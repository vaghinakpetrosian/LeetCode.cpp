class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr)
    {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i)
        {
            dfs(arr, p, i, 0, arr[i][0]);
            dfs(arr, a, i, n - 1, arr[i][n - 1]);
        }
        for(int i = 0; i < n; ++i)
        {
            dfs(arr, p, 0, i, arr[0][i]);
            dfs(arr, a, m - 1, i, arr[m - 1][i]);
        }
        vector<vector<int>> res;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(p[i][j] && a[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

private:
    void dfs(const vector<vector<int>>& arr, vector<vector<bool>>& vis, int i, int j, int prev)
    {
        if(i < 0 || i >= arr.size() || j < 0 || j >= arr[0].size() || vis[i][j] || arr[i][j] < prev)
        {
            return;
        }
        vis[i][j] = true;
        dfs(arr, vis, i + 1, j, arr[i][j]);
        dfs(arr, vis, i - 1, j, arr[i][j]);
        dfs(arr, vis, i, j + 1, arr[i][j]);
        dfs(arr, vis, i, j - 1, arr[i][j]);
    }
};
