/*class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i , n = nums.size();
        sort(nums.begin(),nums.end());
        i = 1 ;
        int length , maxlength = 1;
        while(i<n){
            length = 1;
            while( i<n && (nums[i]==nums[i-1]+1 || nums[i]==nums[i-1])){
                length++;
            }
            maxlength = max(length,maxlength);
            i++;
        }
        return maxlength;
    }
};
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty())
            return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int current = 1;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] == nums[i-1]) {
                continue;
            }

            else if(nums[i] == nums[i-1] + 1) {
                current++;
            }

            else {
                longest = max(longest, current);
                current = 1;
            }
        }

        return max(longest, current);
    }
};
