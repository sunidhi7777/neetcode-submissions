class Solution {
public:
    vector<string> ans ;
    void combo(string digits, int i , string curr){
        if(i== digits.size()){
          ans.push_back(curr);
          return ;
        }
        int num = digits[i]-'0';
        int start ;
        int end ;
        if(num<7){
            start = (num-2)*3 ;
            end = start+2 ;
        }
        switch(num){
            case 7 :
            start = 15 ;
            end = 18 ;
            break ;

            case 8 :
            start = 19 ;
            end = 21 ;
            break ;

            case 9 :
            start = 22 ;
            end = 25 ;
            break ;
        }
        for(int j = start ; j<=end ; j++){
            char ch = 'a' + j; 
            curr.push_back(ch);
            combo(digits , i+1 , curr);
            curr.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
        return {};
        string curr ;
        combo(digits , 0 , curr);
        return ans;
    }
};
