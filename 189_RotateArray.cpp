class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        //int tmp = nums[n - 1];
        int m = k % n;
        if(m == 0)
            return;
       // for(int i = n - 1; i > m; --i)
       // {
       //     int tmp = nums[i];
         //   nums[i] = nums[i - m];
          //  nums[i - m] = tmp;
       // }
       // for(int i = 0; i < m; ++i)
        //{
            //int tmp = nums[i];
            //nums[i] = nums[i + 1];
            //nums[i + 1] = tmp;
        //}
        //nums[m - 1] = tmp;
    for(int i = 0; i < n / 2; ++i)
    {
        int tmp = nums[i];
        nums[i] = nums[n - 1 - i];
        nums[n - 1 - i] = tmp;
    }
    for(int i = 0; i < m / 2; ++i)
    {
        int tmp = nums[i];
        nums[i] = nums[m - 1 - i];
        nums[m - 1 - i] = tmp;
    }
    int j = m + (n - m) / 2;
    for(int i = m; i < j; ++i)
    {
        int tmp = nums[i];
        nums[i] = nums[n - 1 - i + m];
        nums[n - 1 + m - i] = tmp;
    }
    }
};
