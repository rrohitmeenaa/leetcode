// solving this problem using tabulation method of dp 

class Solution {
public:
    int climbStairs(int n) {
        // initializing a dp vector to store the no. of ways to reach index i from the starting index . 
        vector<int> dp(n+1,-1);

        // base cases 
        dp[0] = 1;
        dp[1] = 1;

        for(int i =2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};