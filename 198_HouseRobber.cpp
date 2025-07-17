class Solution {
public: 
    int rob(vector<int>& arr) 
    {
        short n = arr.size();
        short rob1 = 0, rob2 = 0;
        for(short i = 0; i < n; ++i)
        {
            short tmp = rob1 + arr[i] > rob2 ? rob1 + arr[i] : rob2;
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2;
    }
};
