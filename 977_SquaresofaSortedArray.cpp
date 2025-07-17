class Solution {
public:
    int pow(int n)
    {
        return n * n;
    }
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int s = 0, e = nums.size() - 1;
        int size = e + 1;
        while(s < e)
        {
            int mid = s + (e - s) / 2 + 1;
            if(nums[mid] >= 0)
            {
                e = mid - 1;
            }
            else s = mid;
        }
        int i = s, j = s + 1;
        vector<int> res;
        while(i >= 0 && j < size)
        {
            if(pow(nums[i]) > pow(nums[j]))
            {
                res.push_back(pow(nums[j]));
                ++j;
            }
            else
            {
                res.push_back(pow(nums[i]));
                --i;
            }
        }
        while(i >= 0)
        {
            res.push_back(pow(nums[i]));
            --i;
        }
        while(j < size)
        {
            res.push_back(pow(nums[j]));
            ++j;
        }
        return res;
    }
};
