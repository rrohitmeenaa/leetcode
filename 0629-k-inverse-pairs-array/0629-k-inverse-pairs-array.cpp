class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                long long val = dp[i - 1][j];

                if (j > 0)
                    val = (val + dp[i][j - 1]) % MOD;

                if (j >= i)
                    val = (val - dp[i - 1][j - i] + MOD) % MOD;

                dp[i][j] = val;
            }
        }

        return dp[n][k];
    }
};