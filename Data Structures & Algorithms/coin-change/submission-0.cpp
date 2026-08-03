class Solution {
public:
    int further(vector<int>& coins , vector<int>& dp , int amount){
        if(amount == 0)
        return 0 ;
        if(amount < 0)
        return 1e9;
        int val = INT_MAX ;
        int i , n = coins.size();
        if(dp[amount] != -1)
        return dp[amount] ;
        for(i=0 ;i<n ; i++){
            val = min(val , 1+(further(coins , dp , amount-coins[i])));
        }
        return dp[amount]=val ;
    }
    int coinChange(vector<int>& coins, int amount) {
        int i , n = coins.size();
        vector<int> dp (amount+1,-1) ;
        int ans = further(coins , dp , amount);
        return (ans >= 1e9) ? -1 : ans;
    }
};
