class Solution {
private:
    void swap(int& a, int& b)
    {
        int t = a; 
        a = b;
        b = t;
    }
    void heapify(vector<int>& arr, int n, int i)
    {
        int larg = i;
        int l = 2 * i + 2;
        int r = 2 * i + 1;
        if (l < n && arr[l] > arr[i])
        {
            larg = l;
        }
        if (r < n && arr[r] > arr[larg])
        {
            larg = r;
        }
        if (larg != i)
        {
            swap(arr[i], arr[larg]);
            heapify(arr, n, larg);
        }
    }

    void HeapSort(vector<int>& arr)
    {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; --i)
        {
            heapify(arr, n, i);
        }
        for (int i = n - 1; i > 0; --i)
        {
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& arr) 
    {
        HeapSort(arr);
        int n = arr.size();
        vector<vector<int>> res;
        for(int i = 0; i < n; ++i)
        {
            if(i > 0 && arr[i] == arr[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while(l < r)
            {
                int sum = arr[i] + arr[l] + arr[r];
                if(sum > 0)
                {
                    --r;
                    continue;
                }
                if(sum < 0)
                {
                    ++l;
                    continue;
                }
                else
                {
                    res.push_back(vector<int>({arr[i], arr[l], arr[r]}));
                    ++l;
                    while(arr[l] == arr[l - 1] && l < r)
                    ++l;
                    --r;
                }
            }
        }
        return res;
    }
};
