class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) 
    {
        // int n = arr.size();
        // int m = arr[0].size();
        // int i = 0, j = 0, h1 = 0, h2 = 0;
        // vector<int> res;
        // bool flag = false;
        // while()
        // {
        //     if(!flag && h2 % 2 == 0)
        //     {
        //         for(int k = h2; k < m - i; ++ k)
        //         {
        //             res.push_back(arr[h2][k]);
        //         }
        //         ++i;
        //         flag ^= 1;
        //     }
        //     if(!flag && j % 2 == 1)
        //     {
        //         for(int k = m - j - 1; k >= h1; --k)
        //         {
        //             res.push_back(arr[n - 1 - h1][k]);
        //         }
        //         ++h1;
        //         flag ^= 1;
        //     }
        //     if(flag && i % 2 == 1){
        //         for(int k = i; k < n - j; ++k)
        //         {
        //             res.push_back(arr[k][m - 1 - j]);
        //         }
        //         ++j;
        //         flag ^= 1;
        //     }
        //     if(flag && h1 % 2 == 1){
        //         for(int k = n - i - 1; k > i - 1; --k)
        //         {
        //             res.push_back(arr[][k]);
        //         }
        //         ++h2;
        //         flag ^= 1;
        //     }
        // }
        int b = arr.size() - 1;
        int r = arr[0].size() - 1;
        int t = 0, l = 0;
        vector<int> res;
        while(b >= t || r >= l)
        {
            if(t <= b)
            for(int i = l; i <= r; ++ i)
            {
                res.push_back(arr[t][i]);
            }
            ++t;
            if(l <= r)
            for(int i = t; i <= b; ++ i)
            {
                res.push_back(arr[i][r]);
            }
            --r;
            if(t <= b)
            for(int i = r; i >= l; --i)
            {
                res.push_back(arr[b][i]);
            }
            --b;
            if(l <= r)
            for(int i = b; i >= t; --i)
            {
                res.push_back(arr[i][l]);
            }
            ++l;
        }
        return res;
    }
};
