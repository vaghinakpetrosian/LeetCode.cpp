class Solution {
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
public:
    int characterReplacement(string s, int k) 
    {
        int arr[26] = {0};
        int n = s.size();
        int l = 0;
        int m = 0;
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            ++arr[s[i] - 'A'];
            m = max(m, arr[s[i] - 'A']);
            if(i - l + 1 - m > k)
            {
                --arr[s[l] - 'A'];
                ++l;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};
