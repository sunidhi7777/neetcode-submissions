class Solution {
public:
    int total(int n){
        int sum=0;
        while(n>0){
            sum += ((n%10)*(n%10));
            n = n/10;
        }
        return sum ;
    }
    bool isHappy(int n) {
        unordered_set<int> s ;
        while(true){
            int num = total(n) ;
            if(num==1)
            return true;
            if(s.contains(num))
            return false ;
            else
            s.insert(num);
            n = num ;
        }
    }
};
