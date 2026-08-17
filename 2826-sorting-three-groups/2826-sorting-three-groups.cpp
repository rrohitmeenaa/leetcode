

class Solution {
public:
    int solve(vector<vector<int>>& dp,vector<int>& nums,int idx,int prev){
        int n = nums.size();

        if(idx==n){
            return 0;
        }

        if(dp[idx][prev]!=-1){
            return dp[idx][prev];
        }

        int ans = INT_MAX;

        for(int val = prev; val<=3 ; val++){
            int cost = (nums[idx] != val);
            ans = min(ans,cost + solve(dp,nums,idx+1,val));
        }

        return dp[idx][prev] = ans;

    }

    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(4,-1));

        return solve(dp,nums,0,1);
    }
};