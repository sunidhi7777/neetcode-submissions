/*class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        int i=0 , j=0;
        for(char ch : s){
            if(dict[j][i]==ch && j<dict.size()){
                if(i==dict[j].size()-1){
                    j++;
                    i=0 ;
                }else{
                i++;
                }
            }else if(dict[j][i]!=ch){
                return false ;
            }
            return true;
        }
    }
};*/
class Solution {
public:

    bool solve(string &s, vector<string>& wordDict,
               int i, vector<int>& dp){

        if(i == s.size())
            return true;

        if(dp[i] != -1)
            return dp[i];

        for(string word : wordDict){

            int len = word.size();

            if(i + len <= s.size() &&
               s.substr(i, len) == word){

                if(solve(s, wordDict, i + len, dp))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        vector<int> dp(s.size(), -1);

        return solve(s, wordDict, 0, dp);
    }
};
