class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        int left = 0;
        int n = nums.size();
        int right=n-1 ; 
        sort(nums.begin(),nums.end());
        int count = 0 ;
        while(left<=right){
            if(left==right){
                count ++ ;
                right -- ;
                continue ;
            }
            int sum = nums[left] + nums[right];
            if(sum>limit){
                count ++ ;
                right -- ;
            }
            else{
                left ++ ;
                right -- ;
                count ++ ;
            }
        }
        return count ;
    }
};