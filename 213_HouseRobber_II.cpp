class Solution {
public:
    int rob(vector<int>& arr) {
        short n = arr.size();
        if(n == 1)
        return arr[0];
        short rob1 = 0, rob2 = 0;
        for(short i = 0; i < n - 1; ++i)
        {
            short tmp = rob1 + arr[i] > rob2 ? rob1 + arr[i] : rob2;
            rob1 = rob2;
            rob2 = tmp;
        }
        int res1 = rob2;
        rob1 = 0, rob2 = 0;
        for(short i = 1; i < n - 1; ++i)
        {
            short tmp = rob1 + arr[i] > rob2 ? rob1 + arr[i] : rob2;
            rob1 = rob2;
            rob2 = tmp;
        }
        int res2 = rob2 > res1 ? rob2 : res1;
        rob1 = 0, rob2 = 0;
        for(short i = 1; i < n; ++i)
        {
            short tmp = rob1 + arr[i] > rob2 ? rob1 + arr[i] : rob2;
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2 > res2 ? rob2 : res2;
    }
};
