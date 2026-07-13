// number of possible attendance records .
// so we have to use dp here .

class Solution {
public:
    int dp[100001][2][3];
    int MOD = 1e9 + 7;
    int solve(int n,int i,int abs,int late){
        if(i==n){
            return 1;
        }
        if(dp[i][abs][late]!=-1){
            return dp[i][abs][late];
        }
        int a = 0;
        if(abs<1){
            a = solve(n,i+1,abs+1,0)%MOD;
        }
        int l = 0;
        if(late<2){
            l = solve(n,i+1,abs,late+1)%MOD;
        }
        int p = solve(n,i+1,abs,0)%MOD;

        return dp[i][abs][late] = ((a + l)%MOD + p)%MOD;
    }

    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0,0);
    }
};