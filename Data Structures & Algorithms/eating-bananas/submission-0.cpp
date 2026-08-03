class Solution {
public:
    int tym(vector<int> piles , int k){
        int time = 0 ;
        for(int i = 0 ; i<piles.size(); i++){
            time += (piles[i] + k - 1) / k;
        }
        return time ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int mx = *max_element(piles.begin(), piles.end());
        int n = piles.size();
        int mintime = 1 ;
        int maxtime = mx ;
        int mid = (1+mx)/2;
        int ans = mx ;
        while(mintime <= maxtime){
            int time = tym(piles , mid );
            if(time>h){
                mintime = mid+1 ;
            }
            else if(time<=h){
                ans = mid;
                maxtime = mid-1 ;
            }
            mid = (mintime + maxtime)/2 ;
        }
        return ans ;

    }
};
