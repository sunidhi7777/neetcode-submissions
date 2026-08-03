class Solution {
public:
    int findMin(vector<int> &nums) {
        int i , n = nums.size();
        int left = 0 , right = n-1 ;
        int mid = n/2 ;
        while(left<right){
            if(nums[right]<nums[mid])
            left = mid+1 ;
            else// (nums[left]>nums[mid]) 
            right = mid ;
            /*else
            return nums[mid] ;*/
            mid = left + (right - left)/2;
        }
        return nums[left];
    }
};
