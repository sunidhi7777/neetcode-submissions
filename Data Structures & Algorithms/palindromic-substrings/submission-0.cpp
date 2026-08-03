class Solution {
public:
    int check(string s , int i , int j){
        int count=0 ;
        while(i >= 0 && j < s.length() &&  s[i]==s[j] ){
            i-- ;
            j++ ;
            count++ ;
        }
        return count ;
    }
    int countSubstrings(string s){
        int i , n = s.length();
        int count = 0;
        for(i=0;i<n;i++){
            count += check(s,i,i) + check(s,i,i+1);
        }
        return count ;
    }
};
