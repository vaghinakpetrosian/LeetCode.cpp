class Solution {
public:
    // bool isAnagram(string s, string t) {
    //     if (s.size() != t.size())
    //         return false;

    //     unordered_map<char, int> m1, m2;

    //     for (char c : s) m1[c]++;
    //     for (char c : t) m2[c]++;

    //     return m1 == m2;
    // }
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        int arr1[26];
        for (char c : s) ++arr1[c - 97];
        for (char c : t) --arr1[c - 97];
        for(int i = 0; i < 26; ++i)
        {
            if(arr1[i] != 0)
                return false;
        }
        return true;
    }
};
