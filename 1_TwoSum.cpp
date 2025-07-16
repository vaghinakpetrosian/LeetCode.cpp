class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int size = nums.size();
        for(int i = 0; i < size - 1; ++i)
        {
            for(int j = i + 1; j < size; ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    std::vector<int> tmp = {i, j};
                    return tmp;
                }
            }
        }
        return std::vector<int>();
    }
};
