class Solution {
public:
    int find(vector<int>& nums , vector<int>& dp , int i){
        if(i < 0)
            return 0;
        if(i==0)
       // return nums[i];
        // if(i==1)
        return nums[i];
        if(dp[i]!=-1)
        return dp[i];
        return dp[i]=max(nums[i]+find(nums,dp,i-2),find(nums,dp,i-1));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n,-1);
        return (find(nums , dp , n-1));
    }
};
