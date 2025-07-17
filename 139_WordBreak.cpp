class Solution {
private:
    bool cmp(string& s1, string& s2, int i)
    {
        int n = s2.size();
        for(int j = 0; j < n; ++j)
        {
            if(s1[j + i] != s2[j])
            return false;
        }
        return true;
    }
public:
    bool wordBreak(std::string s, std::vector<std::string>& w) {
        int n = s.size();
        int n1 = w.size();
        std::vector<bool> dp(n + 1, false);
        dp[n] = true;
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < n1; ++j) {
                if ((i + w[j].size()) <= n && cmp(s, w[j], i)) {
                    dp[i] = dp[i + w[j].size()];
                }
                if (dp[i]) {
                    break;;
                }
            }
        }
        return dp[0];
    }
};
