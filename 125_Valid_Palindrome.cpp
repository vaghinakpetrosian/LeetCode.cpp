class Solution {
public:
    bool isPalindrome(string s) 
    {
        std::string tmp;
        for(char c : s)
        {
            // if(c > 64 && c < 91)
            //     tmp.push_back(c + 32);
            // else if(c > 96 && c < 123 || c > 47 && c < 58)
            // {
            //     tmp.push_back(c);
            // }
            if (isalnum(c)) {
                tmp.push_back(tolower(c));
            }
        }
        int n = tmp.size();
        for(int i = 0; i < n / 2; ++i)
        {
            if(tmp[i] != tmp[n - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};
