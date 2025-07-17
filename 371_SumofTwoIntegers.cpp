class Solution {
public:
    int getSum(int a, int b) 
    {
        while(b)
        {
            int tmp = a;
            a ^= b;
            b &= tmp;
            b <<= 1;
        }    
        return a;
    }
};
