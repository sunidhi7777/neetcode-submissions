class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i , n = nums.size();
        for(i=0;i<n;i++){
            int x = abs(nums[i]) - 1 ;
            if(nums[x]<0)
            return x+1 ;
            nums[x] *= -1;
        }
    }
};
