class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current ;
        int previous = nums[0];
        if (nums.empty())
            return 0;

        int write = 0;
        for (int read = 1; read < nums.size(); read++) {
            if (nums[read] != nums[write]) {
                write++;
                nums[write] = nums[read];
            }
        }

        return write + 1;
    }
};