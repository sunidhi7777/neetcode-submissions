class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int count = 0 ;
        int i=0 ;
        int left , right ;
        vector<int> ans ;
        while(i < n && nums[i]<x)
           i++ ;
        if(i<n && nums[i]==x){
            count++ ;
            ans.push_back(x);
            left = i-1 ;
            right = i+1 ;
        }else{
            left = i-1 ;
            right = i ;
        }
        while(count<k){
            int diff1,diff2 ;
            if(left>-1)
            diff1 = abs(x-nums[left]);
            else 
            diff1 = 20000 ;
            if(right<n)
            diff2 = abs(nums[right]-x);
            else 
            diff2 = 20000 ;
            if(diff1<diff2){
                ans.push_back(nums[left]);
                left -- ;
            }else if(diff2<diff1){
                ans.push_back(nums[right]);
                right ++ ;
            }else{
                if(left<right){
                    ans.push_back(nums[left]);
                    left -- ;
                }else{
                    ans.push_back(nums[right]);
                    right ++ ;
                }
            }
            count++ ;
        }
        sort(ans.begin(),ans.end());
        return ans ;
    }
};