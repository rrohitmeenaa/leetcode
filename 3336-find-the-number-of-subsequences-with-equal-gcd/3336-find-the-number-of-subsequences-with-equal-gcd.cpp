class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[201][201][201];

    int solve(vector<int>& nums,int i,int g1,int g2){
        if(i== nums.size()){
            return (g1==g2 && g1!=0);
        }
        if(dp[i][g1][g2]!=-1){
            return dp[i][g1][g2];
        }

        long long ans = 0;

        ans = solve(nums,i+1,g1,g2);

        ans = (ans + solve(nums,i+1,gcd(g1,nums[i]),g2))%MOD;

        ans = (ans + solve(nums,i+1,g1,gcd(g2,nums[i])))%MOD;

        return dp[i][g1][g2] = ans%MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,0);
    }
};