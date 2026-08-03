class Solution {
public:

    int dfs(int i,
            int amount,
            vector<int>& coins,
            vector<vector<int>>& dp) {

        if(amount == 0)
            return 1;

        if(amount < 0)
            return 0;

        if(i == coins.size())
            return 0;

        if(dp[i][amount] != -1)
            return dp[i][amount];

        int take = dfs(
            i,
            amount - coins[i],
            coins,
            dp
        );

        int skip = dfs(
            i + 1,
            amount,
            coins,
            dp
        );

        return dp[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(
            n,
            vector<int>(amount + 1, -1)
        );

        return dfs(0, amount, coins, dp);
    }
};