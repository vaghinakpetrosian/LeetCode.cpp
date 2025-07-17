class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        int a = 0, b = 0, s1 = nums1.size(), s2 = nums2.size();
        while(a != s1 && b != s2)
        {
            if(nums1[a] == nums2[b])
            {
                return nums1[a];
            }
            if(nums1[a] > nums2[b])
            {
                ++b;
            }
            else if(nums1[a] < nums2[b])
            {
                ++a;
            }
        }
        return -1;
    }
};
