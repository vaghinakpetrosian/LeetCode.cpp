class Solution {
private:
    int min(int a, int b)
    {
        return a > b ? b : a;
    }
public:
    int coinChange(vector<int>& arr, int amount) 
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        int n = arr.size();
        for(int i = 1; i < amount + 1; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i - arr[j] >= 0)
                {
                    dp[i] = min(dp[i], 1 + dp[i - arr[j]]);
                }
            }
        }
        if(dp[amount] == amount + 1) return -1;
        return dp[amount];
    }
};
