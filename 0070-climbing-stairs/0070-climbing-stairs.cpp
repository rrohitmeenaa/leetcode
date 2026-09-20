// i have to solve the climibing stairs question with all the methods of solving the dp questions which is memoization tabulation and space optimization 

// memoization

class Solution {
public:
    int solve(int idx,vector<int>& dp){
        if(idx==0 || idx==1){
            return 1;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }

        int one = solve(idx-1,dp);
        int two = solve(idx-2,dp);

        return dp[idx] = one + two;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};