class Solution {
public:
    bool isValid(string s) 
    {
        short n = s.size();
        std::string tmp;
        for(short i = 0; i < n; ++i)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                tmp.push_back(s[i]);
            }
            else
            {
                if(tmp.empty())
                    return false;
                char c = tmp.back();
                if(s[i] == ']' && c == '[' || s[i] == '}' && c == '{' || s[i] == ')' && c == '(')
                    tmp.pop_back();
                else return false;
            }
        }    
        return tmp.empty();
    }
};
