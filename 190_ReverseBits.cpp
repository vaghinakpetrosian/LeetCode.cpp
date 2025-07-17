class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        if(!n)
        return 0;
        uint32_t res = 0;
        int k = 32;
        while(n)
        {
            res <<= 1;
            res ^= (n & 1);
            n >>= 1;
            --k;
        }
        res <<= k;
        return res;    
    }
};
