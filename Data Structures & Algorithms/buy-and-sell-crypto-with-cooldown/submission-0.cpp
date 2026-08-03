class Solution {
public:
    int profit(vector<int>& prices , int i , vector<vector<int>>& dp , int buy){
        if(i>= prices.size())
        return 0 ;
        int j = buy;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int p1 =0, p2=0 ;
        if(buy){
            int a = profit(prices, i+1 , dp , 0)-prices[i];
            int b = profit(prices, i+1 , dp , 1);
            p1 = max(a,b);
        }else{
            int a = profit(prices, i+2 , dp , 1)+prices[i];
            int b = profit(prices, i+1 , dp , 0);
            p2 = max(a,b);
        }
        dp[i][j] = max(p1 , p2);
        return dp[i][j];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1)
        return 0 ;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return profit(prices , 0 , dp , 1);
    }
};
