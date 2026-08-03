class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0 , n = nums.size() ;
        int right = n-1 ; 
        while(left<right){
            int sum = nums[left]+nums[right];

            if(sum<target)
                left++;

            if(sum>target)
                right--;

            if(sum==target)
                return {left+1,right+1};
        }
    }
};
