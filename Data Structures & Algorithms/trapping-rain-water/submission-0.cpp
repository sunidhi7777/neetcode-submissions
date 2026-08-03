class Solution {
public:
    int trap(vector<int>& height) {
       int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        while(left < right) {

            if(height[left] < height[right]) {

                leftMax = max(leftMax, height[left]);

                water += leftMax - height[left];

                left++;
            }
            else {

                rightMax = max(rightMax, height[right]);

                water += rightMax - height[right];

                right--;
            }
        }

        return water;
    }
};
/*
 int i , n = height.size();
        int water = 0 , totalwater = 0 ;
        int lp = 0 , rp =0 ; 
        while(rp<n){
            int h1 = height[lp];
            while(h1==0&&lp<n){
                lp++;
                h1 = height[lp];
            }
            rp = lp+1;
            int h2 = height[rp];
            if(h2>h1){
                lp = rp ;
                continue ;
            }
            int obs = 0;
            while(h2<h1 && rp<n){
                h2 = height[rp];
                obs += h2;
                rp++;
            }
            if(h2 >= h1){
                water = (h1*(rp-lp-1))-obs;
                totalwater += water ;
            }
            lp = rp ;
        }
        return totalwater;*/