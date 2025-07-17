class Solution {
private:
    int Max(int a, int b)
    {
        return a > b ? a : b;
    }
    int Min(int a, int b)
    {
        return a < b ? a : b;
    }
public:
    int maxProduct(vector<int>& arr) 
    {
        int res = arr[0];
        int min = 1, max = 1;
        int n = arr.size();
        for(int i = 0; i < n; ++i)
        {
            int tmp = max * arr[i];
            max = Max(arr[i], Max(tmp, arr[i] * min));
            min = Min(arr[i], Min(tmp, min * arr[i]));
            if(res < max)
            res = max;
        }
        return res;
    }
};
