// yes i can solve this question

class Solution {
public:
    int solve(int end ,int start,vector<int>& dp,vector<int>& nums){
        if(end<start)
        {
            return 0;
        }

        if(dp[end]!=-1){
            return dp[end];
        }

        int take = nums[end] + solve(end-2,start,dp,nums);
        int nottake = solve(end-1,start,dp,nums);

        return dp[end] = max(take,nottake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        return max(solve(n-1,1,dp1,nums),solve(n-2,0,dp2,nums));
    }
};