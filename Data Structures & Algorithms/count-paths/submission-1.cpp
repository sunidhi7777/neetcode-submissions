class Solution {
public:
    int path(int i , int j , vector<vector<int>>& dp,int m , int n){
        if(i<0 || i>=m || j<0 || j>=n)
        return 0; 
        if(i == m - 1 && j == n - 1)
        return 1 ;
        if(dp[i][j] != -2)
        return dp[i][j] ;
        int count = path(i+1,j,dp , m , n) + path(i,j+1,dp, m ,n);
        return dp[i][j] = count ;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n,-2));
        return path(0,0,dp ,m , n) ;
    }
};
