class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int s = 0, e = numbers.size() - 1;
        while(s < e)
        {
            int sum = numbers[e] + numbers[s];
            if(sum == target)
            {
                ++s;
                ++e;
                return std::vector<int>  {s, e};
            }
            else if(sum > target)
            {
                --e;
            }
            else
                ++s;
        }
        return std::vector<int>();
    }
};
