class Solution {
private: 
    int pow(int n)
    {
        return n * n;
    }
public:
    int numTrees(int n) 
    {
        if(n == 4)
            return 14;
        if(n == 3)
            return 5;
        if(n == 2)
            return 2;
        if(n == 1)
            return 1;
        if(n == 0)
            return 1;
        if(n % 2 == 0)
        {
            int res = 0;
            for(int i = 0; i < n / 2; ++i)
            {
                res += numTrees(n - i - 1) * numTrees(i);
            }
            return 2 * res;
        }   
        else
        {
            int res = 0;
            for(int i = 0; i < n / 2; ++i)
            {
                res += numTrees(n - i - 1) * numTrees(i);
            }
            return 2 * res + pow(numTrees(n / 2));
        } 
    }
};
// class Solution {
// public:
//     int numTrees(int n) 
//     {
//         vector<int> dp(n + 1, 0);
//         dp[0] = 1;
//         dp[1] = 1;
//         for (int i = 2; i <= n; ++i) 
//         {
//             for (int j = 1; j <= i; ++j) 
//             {
//                 dp[i] += dp[j - 1] * dp[i - j];
//             }
//         }
//         return dp[n];
//     }
// };
