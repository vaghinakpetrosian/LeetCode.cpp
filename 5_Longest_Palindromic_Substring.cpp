// class Solution
// {
//     struct res
//     {
//         res(short l, short r, short len) : l{l}, r{r}, length{len} {}
//         res() : l{0}, r{0}, length{0} {}
//         short l;
//         short r;
//         short length;
//     };
//     res lhelp(string s, short p)
//     {
//         if (p < 0)
//             return res(0, 0, 0);
//         short r = p, l = p;
//         while (l >= 0 && r < s.size() && s[r] == s[l])
//         {
//             r++;
//             l--;
//         }
//         res t1(short(l + 1), short(r - 1), short(r - l - 1));
//         res t2(0, 0, 0);
//         if (p > 0 && s[p] == s[p - 1])
//         {
//             t2 = lhelp(s, p, p - 1);
//         }
//         res t3 = lhelp(s, p - 1);
//         res best = t1;
//         if (t2.length > best.length)
//             best = t2;
//         if (t3.length > best.length)
//             best = t3;
//         return best;
//     }
//     res rhelp(string s, short p, short n)
//     {
//         if (p >= n)
//             return res(0, 0, 0);
//         short r = p, l = p;
//         while (l >= 0 && r < n && s[r] == s[l])
//         {
//             r++;
//             l--;
//         }
//         res t1(short(l + 1), short(r - 1), short(r - l - 1));
//         res t2(0, 0, 0);
//         if (p + 1 < n && s[p] == s[p + 1])
//         {
//             t2 = rhelp(s, p + 1, p, n);
//         }

//         res t3 = rhelp(s, p + 1, n);

//         res best = t1;
//         if (t2.length > best.length)
//             best = t2;
//         if (t3.length > best.length)
//             best = t3;
//         return best;
//     }
//     res lhelp(string s, short r, short l)
//     {
//         while (l >= 0 && r < s.size() && s[l] == s[r])
//         {
//             --l;
//             ++r;
//         }
//         return res(short(l + 1), short(r - 1), short(r - l - 1));
//     }
//     res rhelp(string s, short r, short l, short n)
//     {
//         while (l >= 0 && r < n && s[l] == s[r])
//         {
//             --l;
//             ++r;
//         }
//         return res(short(l + 1), short(r - 1), short(r - l - 1));
//     }

// public:
//     string longestPalindrome(string s)
//     {
//         short n = s.size();
//         if (n == 0)
//             return "";
//         res t1 = lhelp(s, n / 2);
//         res t2 = rhelp(s, n / 2, n);
//         res final_res = (t1.length > t2.length) ? t1 : t2;
//         return s.substr(final_res.l, final_res.length);
//     }
// };

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        int maxm = 0, idx = -1;

        for (int i = 0; i < n; i++)
        {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if ((r - l + 1) > maxm)
                {
                    maxm = r - l + 1;
                    idx = l;
                }
                l--;
                r++;
            }
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if ((r - l + 1) > maxm)
                {
                    maxm = r - l + 1;
                    idx = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(idx, maxm);
    }
};
