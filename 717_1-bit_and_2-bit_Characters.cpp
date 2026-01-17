class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        short n = bits.size();
        short i = 0;
        for(i = 0; i < n - 1;++i)
        {
            if(bits[i])
            ++i;
        }   
        if(i == n)
        return false;
        return true;
    }
};
