// in this question i have to find all the ways 
class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int steps,int k,int i,int arrlen,vector<vector<int>>& dp){
        if(k == steps){
            return(i==0);
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int stay = solve(steps,k+1,i,arrlen,dp);
        int left = 0;
        if(i>0){
            left = solve(steps,k+1,i-1,arrlen,dp);
        }
        int right = 0;
        if(i<arrlen){
            right = solve(steps,k+1,i+1,arrlen,dp);
        }
        return dp[i][k] = ((stay+left)%MOD + right)%MOD;
    }

    int numWays(int steps, int arrlen) {
        int n = arrlen;
        int maxlen = min(arrlen-1,steps/2 + 1);
        vector<vector<int>> dp(maxlen+1,vector<int>(steps+1,-1));
        return solve(steps,0,0,maxlen,dp);
    }
};