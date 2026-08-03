class Solution {
public:
    bool create(vector<int>& nums , int i , int sum , vector<vector<int>>& dp){
        if(sum==0)
        return true ;
        if (sum < 0)
        return false;
        if(i<0)
        return false ;
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        bool a = create(nums,i-1,sum,dp) ;
        bool b = create(nums,i-1,sum-nums[i],dp);
        dp[i][sum]=(a || b) ;
        return dp[i][sum];
    } 
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0 )
        return false ;
        sum = sum/2 ;
        vector<vector<int>> dp(nums.size(),
                               vector<int>(sum +1 , -1));
        return create(nums , nums.size()-1 , sum , dp);
    }
};
