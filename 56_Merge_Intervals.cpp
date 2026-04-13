class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) 
            return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (const auto& interval : intervals) {
            if (res.back()[1] < interval[0]) 
            {
                res.push_back(interval);
            } 
            else 
            {
                res.back()[1] = res.back()[1] > interval[1] ? res.back()[1] : interval[1];
            }
        }
        return res;
    }
};
