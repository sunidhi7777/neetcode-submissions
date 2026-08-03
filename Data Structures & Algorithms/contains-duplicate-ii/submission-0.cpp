class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> visited ;
        for(int i=0 ; i<k ; i++){
            if(visited.contains(nums[i]))
            return true ;
            visited.insert(nums[i]);
        }
        for(int i=k ; i<n ; i++){
            if(visited.contains(nums[i]))
            return true ;
            visited.insert(nums[i]);
            visited.erase(nums[i-k]);
        }
        return false ;
    }
};