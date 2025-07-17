class Solution {
private:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
public:
    int lengthOfLIS(vector<int>& arr) 
    {
        int n = arr.size();   
        vector<int> dp(n, 1);
        dp[n - 1] = 1;
        int res = 1;
        for(int i = n - 2; i >= 0; --i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(arr[j] > arr[i])
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            res = max(dp[i], res);
        }
        return res;
    }
};
