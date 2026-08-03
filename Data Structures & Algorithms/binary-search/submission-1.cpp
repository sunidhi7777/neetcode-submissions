class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i , n = nums.size();
        int left = 0 , right = n-1 ;
        int mid = n/2 ;
        while(left<=right){
            if(target>nums[mid])
            left = mid+1 ;
            else if(target<nums[mid]) 
            right = mid-1 ;
            else
            return mid ;
            mid = left + (right - left)/2;
        }
        /*if(nums[left]==target || nums[right]==target)
        return left ;
        else*/
        return -1;
    }
};
