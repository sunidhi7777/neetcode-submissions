class Solution {
public:
    vector<vector<int>> ans;
    void combos(vector<int>& nums, int target , vector<int> &branch , int sum , int i ){
        if(sum==target){
            ans.push_back(branch);
            return;
        }
        if(sum>target)
        return ;
        if(i == nums.size()) {
            return;
        }
        branch.push_back(nums[i]);
        sum += nums[i];
       // combos(nums , target , branch , sum , i+1) ;
        combos(nums , target , branch , sum , i) ;
        sum = sum-nums[i];
        branch.pop_back();

        combos(nums , target , branch , sum , i+1) ;

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> branch ;
        combos(nums , target , branch , 0 , 0) ;
        return ans ;
    }
};
