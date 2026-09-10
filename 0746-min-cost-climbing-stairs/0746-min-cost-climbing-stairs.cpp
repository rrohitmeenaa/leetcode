// i can start either with step 1 or step 2 and i have to return the min cost 
// here dp[i] means the min cost to reach stair i .
class Solution {
public:
    int solve(int idx,vector<int>& dp,vector<int>& cost){
        int n = cost.size();
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int left = cost[idx] + solve(idx+1,dp,cost) ;
        int right = cost[idx] + solve(idx+2,dp,cost);

        return dp[idx] = min(left,right);

    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(0,dp,cost),solve(1,dp,cost));
    }
};