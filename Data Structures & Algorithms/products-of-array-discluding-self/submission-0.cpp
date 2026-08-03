/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int  i , n = nums.size();
        int pre = 1 , suf = 1 ;
        vector<int> prefix(n);
        vector<int> suffix(n);
        suffix[n-1] = 1;
        prefix[0] = 1;
        int prod=1;
        vector<int> ans ;
        for(i=n-2;i>=0;i--){
            suf *= nums[i+1];
            suffix[i]=suf;
        }
        for(i=0;i<n;i++){
            pre *= nums[i-1] ;
            prod = pre*suffix[i];
            ans.push_back(prod);
        }
        return ans;
        
    }
};
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        int pre = 1, suf = 1;

        vector<int> suffix(n);

        suffix[n-1] = 1;

        vector<int> ans;

        for(int i = n-2; i >= 0; i--) {
            suf *= nums[i+1];
            suffix[i] = suf;
        }

        for(int i = 0; i < n; i++) {

            int prod = pre * suffix[i];

            ans.push_back(prod);

            pre *= nums[i];
        }

        return ans;
    }
};