class Solution
{
    public:
        vector<vector<int>> insert(vector<vector<int>> &n, vector<int> &m)
        {
            if(!n.size())
                return vector<vector<int>> {m};
            short size = n.size();
            short first = m[0], second = m[1];
            short i = 0;
            vector<vector<int>> res;
            while(i < size)
            {
                if(n[i][1] < m[0])
                {
                    res.push_back(n[i]);
                }
                else
                {
                    if(n[i][0] <= m[0])
                    {
                        first = n[i][0];
                    }
                    break;
                }
                ++i;
            }
            while(i < size)
            {
                if(n[i][1] < m[1])
                {
                    ++i;
                }
                else
                {
                    if(n[i][0] <= m[1])
                    {
                        second = n[i][1];
                        ++i;
                    }
                    break;
                }
            }
            res.push_back({first, second});
            while(i < size)
            {
                res.push_back(n[i]);
                ++i;
            }
            return res;
        }
};
