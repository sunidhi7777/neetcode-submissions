class Solution {
public:
    int solve(vector<int>& nums, int target , vector<int>& dp ){
        if(target == 0)
        return 1 ;
        if(target<0)
        return 0;
        if(dp[target] != -1)
            return dp[target];
           // dp[target] = 0 ;
        dp[target] = 0;
        for(int num : nums){
            dp[target] += solve(nums , target-num , dp);
        }
        return dp[target];
    } 
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1 , -1);
        return solve(nums , target, dp);
    }
};