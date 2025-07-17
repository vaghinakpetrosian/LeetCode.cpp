class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        int s = 0; 
        int size = nums.size();
        int e = size - 1;
        int mid = 0;
        while(s < e)
        {
            mid = s + (e - s) / 2;
            if(nums[mid] >= 0)
            {
                e = mid;
            }
            else s = mid + 1;
        }
        while(s >= 0 && nums[s] >= 0)
        {
            --s;
        }
        while(e < size && nums[e] <= 0)
        {
            ++e;
        }
        return size - e > s ? size - e : s + 1;
    }
};
