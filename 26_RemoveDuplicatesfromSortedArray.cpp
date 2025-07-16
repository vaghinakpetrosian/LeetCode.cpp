class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int tmp = nums[0] - 1;
        int i = 0;
        int j = 1;
        int k = 0;
        int size = nums.size();
        while(i < size)
        {
        while(j < size && nums[i] == nums[j])
        {
            nums[j] = tmp;
            ++j;
            ++k;
        }
            i = j;
            ++j;
        }
        int res = size - k;
        for(int z = 1; z < size - 1; ++z)
        {
            if(z == res)
                break;
            if(nums[z] == tmp)
            {
                int c = z + 1;
                while(c < size && nums[c] == tmp)  {
                    ++c;}
                int t = nums[z];
                nums[z] = nums[c];
                nums[c] = t;
            }
        }
    return res;
    }
};
