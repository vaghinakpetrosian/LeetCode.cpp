class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& arr) 
    {
        int n = arr.size();
        std::vector<int> res(n,1);
        for(int i = 1; i < n; ++i)
        {
            res[i] *= (res[i - 1] * arr[i - 1]);
        }   
        int tmp = 1;
        for(int i = n - 2; i >= 0; --i)
        {
            tmp *= arr[i + 1];
            res[i] *= tmp;
        }
        return res;
    }
};
