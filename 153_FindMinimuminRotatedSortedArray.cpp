class Solution
{
public:
    //int findMin(std::vector<int> &arr)
    // {
    //     return foo(arr, 0, arr.size() - 1);
    // }
    // int foo(std::vector<int>& arr, int l, int r)
    // {
    //     if (l >= r)
    //         return arr[r];
    //     if (arr[l] < arr[r])
    //         return arr[l];
    //     int mid = l + (r - l) / 2;
    //     if (arr[mid] < arr[l])
    //         return foo(arr, l, mid);
    //     else
    //         return foo(arr, mid + 1, r);
    // }
    int findMin(std::vector<int>& arr)
    {
        int l = 0, r = arr.size() - 1;
        while(l < r)
        {
            if(arr[l] < arr[r])
                return arr[l];
            int mid = l + (r - l) / 2;
            if(arr[mid] > arr[r])
                l = mid + 1;
            else
                r = mid;
        }
        return arr[r];
    }
};
