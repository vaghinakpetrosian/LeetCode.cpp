#include <iostream>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = size - 2;
        int tar = 0;
        while(i >= 0)
        {
           if(nums[i + 1] > nums[i])
               {
                   tar = i;
                   break;
               } 
            --i;
        }
        if(i == -1)
            {
            i=0;
            while(i < size / 2)
                {
                int tmp = nums[i];
               nums[i] = nums[size - 1 - i];
               nums[size - 1 - i] = tmp;
                ++i;
            }
            //std::cout << nums;
           return; 
        }
        i = size - 1;
          while(nums[tar] >= nums[i])
              {
              --i;
              }
        int tmp = nums[tar];
        nums[tar] = nums[i];
        nums[i] = tmp;
        i = size - 1;
        ++tar;
        while(tar < i)
        {
            tmp = nums[tar];
            nums[tar] = nums[i];
            nums[i] = tmp;
            --i;
            ++tar;
        }
        //std::cout << nums;
    }
};
