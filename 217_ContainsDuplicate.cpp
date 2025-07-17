class Solution {
public:
    void swap(int& a, int& b)
    {
        int mp = a;
        a = b;
        b = mp;
    }
    void heapify(vector<int>& nums,int n, int i)
    {
        int larg = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if(r < n && nums[r] > nums[i])
            larg = r;
        if(l < n && nums[l] > nums[larg])
            larg = l;
        if(larg != i)
        {
            swap(nums[i], nums[larg]);
            heapify(nums, n, larg);
        }
    }
    void sort(vector<int>& nums)
    {
        int size = nums.size();
        for(int i = size / 2 - 1; i >= 0; --i)
        {
            heapify(nums,size, i);
        }
        for(int i = size - 1; i > 0; --i)
        {
            swap(nums[0], nums[i]);
            heapify(nums,i, 0);
        }
    }
    bool containsDuplicate(vector<int>& nums) 
    {
        sort(nums);
        int size = nums.size();
        for(int i = 0; i < size - 1; ++i)
        {
            if(nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
};
