// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) 
//     {
//         unordered_map<int, int> m;
//         for (int i = 0; i < nums.size(); ++i) {
//             int complement = target - nums[i];
//             if (m.count(complement)) {
//                 return {m[complement], i};
//             }
//             m[nums[i]] = i;
//         }
//         return {};
//     }

// };

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
