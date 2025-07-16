class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int max = nums[0];
        int a = nums[0];
        int size = nums.size();
        for(int i = 1; i < size; ++i)
        {
            if(a < 0)
            {
                a = 0;
            }
            a += nums[i];
            if(max < a)
            {
                max = a;
            }
        }
        return max;
    }
};
