class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> res(n + 1);
        res[0] = 0;
        int ast = 1;
        for(int i = 1; i < n + 1; ++i)
        {
            if(i == ast * 2)
            ast *= 2;
            res[i] = 1 + res[i - ast];
        }    
        return res;
    }
};
