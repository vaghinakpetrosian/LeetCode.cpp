class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int tmp = nums[0], size = nums.size();
        for(size_t i = 1; i < size; ++i)
        {
            tmp ^= nums[i];
        }
        return tmp;
    }
};
