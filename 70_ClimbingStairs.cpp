class Solution {
public:
    int climbStairs(int n) 
    {
        // if(n == 1)
        //     return 1;
        // if(n == 2)
        //     return 2;
        // return climbStairs(n - 1) + climbStairs(n - 2); 
        if (n <= 1)
            return n;
        int prev1 = 1, prev2 = 1;
        int current;
        for (int i = 2; i <= n; ++i) 
        {
            current = prev1 + prev2; 
            prev1 = prev2;          
            prev2 = current;
        }
        return current;
    }
};
