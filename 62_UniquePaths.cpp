class Solution {
private:
    // int fac(int a, int b)
    // {
    //     long long int res1 = 1, res2 = 1;
    //     for(int i = a; i > a - b; --i)
    //     {
    //         res1 *= i;
    //     }
    //     for(int i = 2; i <= b; ++i)
    //     {
    //         res2 *= i;
    //     }
    //     return res1 / res2;
    // }
public:
    int uniquePaths(int m, int n) 
    {
        // if(m == 1 || n == 1)
        // {
        //     return 1;
        // }
        // int tmp = n - 1;
        // n += m - 2;
        
        // if(tmp > m)
        //     return fac(n, m - 1);
        // return fac(n, tmp);
        // return uniquePaths(n - 1, m) + uniquePaths(n, m - 1);
        // vector<vector<int>> dp;
        // for(short i = 0; i < n; ++i)
        // {
        //     dp.push_back(vector<int>(m));
        // }
        // for(short i = 2; i <= n; ++i)
        // {
        //     dp[n - i][m - 1] = 1;
        // }
        // for(short i = 2; i <= m; ++i)
        // {
        //     dp[n - 1][m - i] = 1;
        // }
        // for(short i = n - 2; i >= 0; --i)
        // {
        //     for(short j = m - 2; j >= 0; --j)
        //     {
        //         dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        //     }
        // }
        // return dp[0][0];
        short N = n + m - 2;
        short R = n > m ? m - 1 : n - 1;
        long long res = 1;
        for(short i = 1; i <= R; ++i){
            res = res * (N - R + i) / i;
        }
        return (int)res;
    }
};
