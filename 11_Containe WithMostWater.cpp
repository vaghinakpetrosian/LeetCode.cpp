class Solution {
public:
    int maxArea(vector<int>& arr) 
    {
        int l = 0;
        int r = arr.size() - 1;
        int res = 0;
        while(l < r)
        {
            if(arr[l] < arr[r])
            {
                if(arr[l] * (r - l) > res)
                res = arr[l] * (r - l);
                ++l;
            }
            else
            {
                if(arr[r] * (r - l) > res)
                res = arr[r] * (r - l);
                --r;
            }
        }
        return res;
    }
};
