class Solution {
public:
    int hammingWeight(int n) 
    {
        if(!(n & (n - 1)))
        return 1;
        int x = 0;
        while(n)
        {
            x += (n & 1);
            n >>= 1;
        }    
        return x;
    }
};
