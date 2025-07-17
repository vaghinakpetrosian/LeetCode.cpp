class Solution {
public:
    int missingNumber(vector<int>& arr) 
    {
        int n = arr.size();    
        int sum = n * (n + 1) / 2;
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            res += arr[i];
        }
        return sum - res;
    }
};
