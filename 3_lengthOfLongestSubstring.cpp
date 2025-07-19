// class Solution {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         unordered_map<char, int> m;
//         int a = 0;
//         int max = 0;
//         int j = 0;
//         for(int i = 0; i < s.size(); ++i)
//         {
//             if(!m.count(s[i]))
//             {
//                 ++a;
//                 m[s[i]] = i;
//             }
//             else
//             {
//                 while(m.count(s[i]))
//                 {
//                     m.erase(s[j]);
//                     ++j;
//                     --a;
//                 }
//                 m[s[i]] = s[i];
//                 ++a;
//             }
//             if(a > max)
//             {
//                 max = a;
//             }
//         }   
//         return max; 
//     }
// };
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (lastSeen.count(c) && lastSeen[c] >= start) {
                start = lastSeen[c] + 1;
            }
            lastSeen[c] = i;
            maxLen = maxLen > i - start + 1 ? maxLen : i - start + 1;
        }

        return maxLen;
    }
};
