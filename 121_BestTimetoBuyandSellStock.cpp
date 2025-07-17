class Solution {
public:
    int maxProfit(vector<int>& arr) 
    {
        int n = arr.size();
        //int l = 0, r  = 1;
        int res = 0;
        int j = 0, i = 1;
        while(i < n)
        {
            if(arr[i] > arr[j])
            {
                if(arr[i] - arr[j] >= res)
                {
                    res = arr[i] - arr[j];
                    //r = i; 
                    //l = j;
                }
            }
            else if(arr[i] < arr[j])j = i;
            ++i;
        }    
        return res;
    }
};
