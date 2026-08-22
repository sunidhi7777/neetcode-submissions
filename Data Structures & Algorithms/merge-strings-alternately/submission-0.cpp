class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int length = n>m ? m : n ;
        string ans ;
        for(int i=0 ; i<length  ; i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        int i = length ;
        while(i<n){
            ans.push_back(word1[i++]);
        }
        while(i<m){
            ans.push_back(word2[i++]);
        }
        return ans ;
    }
};