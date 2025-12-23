class Solution {
public:
    string minWindow(string s, string t) 
    {
        int arr[58] = {0};
        for (char c : t) arr[c - 'A']++;
        int m = t.size();
        int n = s.size();
        int have = 0;
        int l = 0, r = 0;
        int resl = 0, minLen = INT_MAX;
        while (r < n)
        {
            if (arr[s[r] - 'A'] > 0) 
                have++;
            arr[s[r] - 'A']--;
            while (have == m) 
            {
                if (r - l + 1 < minLen) 
                {
                    minLen = r - l + 1;
                    resl = l;
                }
                arr[s[l] - 'A']++;
                if (arr[s[l] - 'A'] > 0) 
                    have--; 
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(resl, minLen);
    }
};
