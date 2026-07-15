class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[10001][7][7];
    int solve(int n,int idx,int val,int prev){
        if(idx==n){
            return 1;
        }
        if(dp[idx][val][prev]!=-1){
            return dp[idx][val][prev];
        }
        int take = 0;
        for(int i = 1;i<=6;i++){
            if(i!=val && i!=prev && gcd(i,val)==1){
                take = (take + solve(n,idx+1,i,val))%MOD;
            }
        }
        return dp[idx][val][prev] = take % MOD;
    }

    int distinctSequences(int n) {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i = 1;i<=6;i++){
            ans = (ans+solve(n,1,i,0))%MOD;
        }
        return ans;
    }
};