class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        int half = (m + n + 1) / 2;

        while (low <= high) {

            int cutA = (low + high) / 2;
            int cutB = half - cutA;

            int leftA;
            int rightA;
            int leftB;
            int rightB;

            if (cutA == 0)
                leftA = INT_MIN;
            else
                leftA = nums1[cutA - 1];

            if (cutA == m)
                rightA = INT_MAX;
            else
                rightA = nums1[cutA];

            if (cutB == 0)
                leftB = INT_MIN;
            else
                leftB = nums2[cutB - 1];

            if (cutB == n)
                rightB = INT_MAX;
            else
                rightB = nums2[cutB];

            // Correct partition
            if (leftA <= rightB && leftB <= rightA) {

                // Odd total number of elements
                if ((m + n) % 2 == 1) {
                    return max(leftA, leftB);
                }

                // Even total number of elements
                return (max(leftA, leftB) +
                        min(rightA, rightB)) / 2.0;
            }

            // Took too many elements from A
            else if (leftA > rightB) {
                high = cutA - 1;
            }

            // Took too few elements from A
            else {
                low = cutA + 1;
            }
        }

        return 0.0;
    }
};
