class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sumo = 0 ;
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> mp ;
        vector<int> sum ;
        for(int i=0 ; i<n ; i++){
            sumo += nums[i];
            sum.push_back(sumo);
        }
        for(int i=0 ; i<n ; i++){
            if(sum[i]==k)
            count ++ ;

            int tofind = sum[i]-k ;
            if(mp.find(tofind) != mp.end())
              count += mp[tofind];

            if(mp.find(sum[i]) == mp.end())
               mp[sum[i]] = 0 ;
            mp[sum[i]] ++ ;

        }
        return count ;
    }
};