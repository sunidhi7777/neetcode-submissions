class Solution {
public:
    vector<vector<int>> ans ;

    void swapy(int a , int b , vector<int>& nums){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b]= temp ;
    }
    
    void getperm(int i , vector<int>& nums , vector<int>& branch){

        if(i==nums.size()){
            ans.push_back(branch);
            return ;
        }
        int n = nums.size();
        int a ;
        for(a=i;a<n;a++){
            swapy(a,i,nums);
            branch.push_back(nums[i]);
            getperm(i+1,nums,branch);
            branch.pop_back();
            swapy(a,i,nums);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> branch ;
        getperm(0,nums , branch );
        return ans ;
    }
};
