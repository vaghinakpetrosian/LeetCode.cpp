class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0) 
            return false;
        if(x < 10)
            return true;
        int tmp = x;
        size_t rev = 0;
        while(tmp)
        {
            rev *= 10;
            rev += tmp % 10;
            tmp /= 10;
        }
        return rev == x;
    }
};
