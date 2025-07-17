class Solution {
public:
    int findGCD(vector<int>& nums) 
    {
        int size = nums.size();
        int min = nums[0];
        int max = min;
        for(int i = 1; i < size; ++i)
        {
            if(nums[i] > max)
                max = nums[i];
            if(nums[i] < min)
                min = nums[i];
        }
        while(min)
        {
            int tmp = min;
            min = max % min;
            max = tmp;
        }
        return max; 
    }
};
