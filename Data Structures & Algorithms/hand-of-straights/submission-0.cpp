class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gp) {
      if(hand.size() % gp != 0)
            return false;
       map<int,int> mp ;
       for(int num : hand){
         mp[num] ++ ;
       }
       for(auto &it : mp){
        if(it.second == 0)
         continue ;
        if(it.second < 0)
         return false ;
         int val = it.second ;
         for(int i = 0; i < gp; i++){
                if(mp[it.first + i] < val)
                    return false;

                mp[it.first + i] -= val;
            }
        }
       return true ;
    }
};
