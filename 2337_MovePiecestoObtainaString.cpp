class Solution {
public:
    bool canChange(string start, string target) 
    {
        int n = start.size();
        int j = 0, c1 = n, c2 = n;
        for(int i = 0; i < n; ++i)
        {
            while(i < n && target[i] == '_')
            {
                --c1;
                ++i;
                continue;
            }
            while( j < n && start[j] == '_')
            {
                --c2;
                ++j;
                continue;
            }
            if(j == n)
            break;
            if(target[i] == 'L')
            {
                if(j < i || 'L' != start[j])
                return false;
                else ++j;
            }
            if(target[i] == 'R')
            {
                if(j > i || 'R' != start[j])
                return false;
                else ++j;
            }
        }
        return start[j] == '_' || c1 == c2;
    }
};
