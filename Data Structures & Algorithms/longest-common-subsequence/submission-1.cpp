class Solution {
public:
    int check(string& s1, string& s2 , int i , int j , vector<vector<int>>& dp){
        if(i<0 || j<0)
        return 0 ;
        int add = 0;
        if(s1[i]==s2[j])
        add = 1 ;
        if(dp[i][j]!= -1)
        return dp[i][j];
        dp[i][j] = max(check(s1,s2,i-1,j-1,dp)+add,max(check(s1,s2,i-1,j,dp),check(s1,s2,i,j-1,dp)));
        return dp[i][j];
    }
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return check(s1,s2,s1.size()-1,s2.size()-1,dp);
    }
};
