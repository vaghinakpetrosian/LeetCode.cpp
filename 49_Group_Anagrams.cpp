class Solution {
    int key(std::string c)
    {
        int res = 0;
        return 0;
    }
    struct ArrayHasher {
    std::size_t operator()(const std::array<short, 26>& arr) const {
        std::size_t hash = 0;
        for (short n : arr) {
            hash ^= std::hash<short>{}(n) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        std::unordered_map<std::array<short, 26>, std::vector<string>, ArrayHasher> map;

        short n = strs.size();
        for(short i = 0; i < n; ++i)
        {
            short m = strs[i].size();
            std::array<short, 26> tmp{};
            for(short j = 0; j < m; ++j)
            {
                ++tmp[strs[i][j] - 'a'];
            }
            map[tmp].push_back(strs[i]);
        }  
        std::vector<vector<string>> res;
        for(auto& tmp : map)
        {
            res.push_back(tmp.second);
        }
        return res;
    }
};
