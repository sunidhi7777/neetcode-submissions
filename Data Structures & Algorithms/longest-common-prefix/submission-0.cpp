class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i , n = strs.size();
        int letter = 0 ;
        string ans ;
        while(1){
            if(letter >= strs[0].size())
            break;
            if(strs[0][letter]!='\0'){
                char current = strs[0][letter];
            for(i=0;i<n;i++){
                if(strs[i][letter]!=current || strs[i][letter]=='\0')
                return ans ;
            }
            letter++ ;
            ans.push_back(current);
            }
            else break ;
        }
        return ans ;
    }
};