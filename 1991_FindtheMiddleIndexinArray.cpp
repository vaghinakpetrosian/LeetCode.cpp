class Solution {
public:
    int findMiddleIndex(vector<int>& nums) 
    {
        int size = nums.size();
        int f = 0, l = 0, i = 0;
        for(i = size - 1; i > 0; --i)
        {
            l += nums[i];
        } 
        while(f != l)
        {
            f += nums[i];
            l -= nums[i + 1];
            ++i;
            if(i == size - 1 && f != l)
                return -1;
        }
        return i;
    }
};
