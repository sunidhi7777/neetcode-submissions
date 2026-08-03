class Solution {
public:
    vector<vector<int>> ans;
    void combos(vector<int>& nums, int target , vector<int> &branch , int sum , int i ){
        if(sum==target){
            ans.push_back(branch);
            return;
        }
        if(i == nums.size() || sum>target) {
            return;
        }
        branch.push_back(nums[i]);
        sum += nums[i];
        combos(nums , target , branch , sum , i+1) ;
        sum = sum-nums[i];
        branch.pop_back();

        int j = i;
        while(j + 1 < nums.size() && nums[j] == nums[j+1])
        j++;

        combos(nums , target , branch , sum , j+1) ;

    }
    vector<vector<int>> combinationSum2(vector<int>& candy, int target) {
        vector<int> branch ;
        sort(candy.begin(),candy.end());
        combos(candy , target , branch , 0 , 0) ;
        return ans ;
    }
};