class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            int x = nums[i];

            int tempMax = max({x,
                               x * currMax,
                               x * currMin});

            int tempMin = min({x,
                               x * currMax,
                               x * currMin});

            currMax = tempMax;
            currMin = tempMin;

            ans = max(ans, currMax);
        }

        return ans;
    }
};