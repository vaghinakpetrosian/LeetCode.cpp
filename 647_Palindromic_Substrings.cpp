class Solution {
public:
    int countSubstrings(string s) 
    {
        string t = "^";
        for (char c : s) {
            t += "#";
            t += c;
        }
        t += "#$";
        int sum = 0;
        int n = t.length();
        vector<int> P(n, 0);
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * C - i;
            if (i < R)
                P[i] = min(R - i, P[i_mirror]);
            while (t[i + 1 + P[i]] == t[i - 1 - P[i]])
                P[i]++;
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        sum += (P[i] + 1) / 2;
        }
        return sum;
    }
};
