class Solution {
public:
    double myPow(double x, int n) {
        double val = 1 ;
        bool inverse = false ;
        if(n<0){
            n = -n ;
            inverse = true ; 
        }
        while(n--){
            val = val*x ;
        }
        if(inverse == true)
        val = 1.00000/val ;
        return val ;
    }
};
