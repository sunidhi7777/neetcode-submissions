class Solution {
public:
    vector<vector<int>> ans ;
    void subs(vector<int>& nums , vector<int>& branch ,int i){
        if(i==nums.size()){
            ans.push_back(branch);
            return ;
        }
        branch.push_back(nums[i]);
        subs(nums , branch , i+1);
        branch.pop_back() ;
        int x=i+1 ;
        while(x < nums.size() && nums[i]==nums[x]){
            x++ ;
        }
        subs(nums , branch , x);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());   
        vector<int> branch ;
        subs(nums,branch,0);
        return ans;
    }
};
