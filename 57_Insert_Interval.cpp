class Solution
{
private:
    int binarleft(vector<vector<int>> &arr, int t)
    {
        int b = 0, e = arr.size() - 1;
        int mid = 0;
        while (e > b)
        {
            mid = b + (e - b) / 2;

            if (t < arr[mid][0])
            {
                e = mid;
            }
            else
            {
                if (t > arr[mid][0])
                {
                    if (t <= arr[mid][1])
                        return mid;
                    else
                    {
                        if (t > arr[mid][1])
                            b = mid + 1;
                    }
                }
                else
                {
                    return mid;
                }
            }
        }
        return b;
    }
    int binarright(vector<vector<int>> &arr, int t)
    {
        int b = 0, e = arr.size() - 1;
        int mid = 0;
        while (e > b)
        {
            mid = e + (b - e) / 2;

            if (t > arr[mid][1])
            {
                b = mid;
            }
            else
            {
                if (t < arr[mid][1])
                {
                    if (t >= arr[mid][0])
                    {
                        return mid;
                    }
                    else
                    {
                        if (t < arr[mid][0])
                            e = mid - 1;
                    }
                }
                else
                {
                    return mid;
                }
            }
        }
        return e;
    }
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int min(int a, int b)
    {
        return a < b ? a : b;
    }

public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        if(intervals.size() == 0)
            return vector<vector<int>>({newInterval});
        int r = binarleft(intervals, newInterval[1]);
        int l = binarright(intervals, newInterval[0]);
        if (l == r)
        {
            if(l == 0 && newInterval[0] < intervals[0][0])
            {
                if(newInterval[1] < intervals[0][0])
                {
                    std::vector<vector<int>> res;
                    res.push_back(newInterval);
                    res.insert(res.end(), intervals.begin(), intervals.end());
                    return res;
                }
                else{
                    intervals[0][0] = newInterval[0];
                }
            }
            if (r == intervals.size() - 1 && newInterval[1] > intervals[intervals.size() - 1][1])
            {
                if (newInterval[0] > intervals[intervals.size() - 1][1])
                    intervals.push_back(newInterval);
                else
                    intervals[intervals.size() - 1][1] = newInterval[1];
                return intervals;
            }
            if(newInterval[0] < intervals[l][0])
            intervals[l][0] = newInterval[0];
            if(newInterval[1] > intervals[l][1])
            intervals[l][1] = newInterval[1];
            return intervals;
        }
        if (newInterval[0] > intervals[l][1] && newInterval[1] < intervals[r][0])
        {
            intervals.insert(intervals.begin() + r, newInterval);
            return intervals;
        }
        std::vector<vector<int>> res;
        if (newInterval[0] > intervals[l][1] && newInterval[1] >= intervals[r][0])
        {
                //return vector<vector<int>>();
            intervals[r][0] = newInterval[0];
            intervals[r][1] = max(intervals[r][1], newInterval[1]);
            return intervals;
        }
        if (newInterval[0] <= intervals[l][1] && newInterval[1] < intervals[r][0])
        {
            res.insert(res.end(), intervals.begin(), intervals.begin() + l + 1);
            res[l][1] = max(intervals[r - 1][1],newInterval[1]);
            res.insert(res.end(), intervals.begin() + r, intervals.end());
            return res;
        }
        if(newInterval[0] <= intervals[l][1] && newInterval[1] >= intervals[r][0])
        {
            res.insert(res.end(), intervals.begin(), intervals.begin() + l + 1);
            res[l][1] = max(intervals[r][1],newInterval[1]);
            res.insert(res.end(), intervals.begin() + r + 1, intervals.end());
            if(res.size() == 1)
            {
                res[0][0] = min(intervals[0][0],newInterval[0]);
                res[0][1] = max(intervals[intervals.size() - 1][1],newInterval[1]);
            }
            if(res.size() == intervals.size())
            {
                res[res.size() - 1][0] = min(intervals[res.size() - 1][0],newInterval[0]);
                res[res.size() - 1][1] = max(intervals[res.size() - 1][1],newInterval[1]);
            }
        }
        return res;
    }
};
