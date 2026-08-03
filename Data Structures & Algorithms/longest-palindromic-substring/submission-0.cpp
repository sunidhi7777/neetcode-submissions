class Solution {
public:
    
    int expand(string& s, int left, int right) {

        while(left >= 0 &&
              right < s.length() &&
              s[left] == s[right]) {

            left--;
            right++;
        }

        // actual palindrome length
        return right - left - 1;
    }

    string longestPalindrome(string s) {

        int start = 0;
        int maxLen = 1;

        for(int i = 0; i < s.length(); i++) {

            int len1 = expand(s, i, i);       // odd length
            int len2 = expand(s, i, i + 1);   // even length

            int len = max(len1, len2);

            if(len > maxLen) {

                maxLen = len;

                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};
/*
class Solution {
public:
    int check(string s , int i , int j){
        int length=0 ;
        while(i >= 0 && j < s.length() &&  s[i]==s[j] ){
            length++ ;
            i-- ;
            j++ ;
        }
        return length ;
    }
    string longestPalindrome(string s) {
        int i , n = s.length();
        int maxlen = 0;
        string a ;
        for(i=0;i<n-1;i++){
            int len = max(check(s,i,i) , check(s,i,i+1));
            if(len>maxlen){
                maxlen = len ;
                string
            }
        }
        return maxlen ;
    }
};*/