class Solution {
public:
    vector<string> ans ; 
    bool isValid(string s) {
        int i , n = s.size();
        stack<char> st ;
        for(i=0; i<n ; i++){
            if(s[i]=='(' || s[i]=='{'|| s[i]=='[')
             st.push(s[i]);
            else if(st.empty())
              return false;
            else if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{')|| (s[i]==']' && st.top()=='['))
             st.pop();
            else 
            return false ; 
        }
        if(st.empty())
        return true ;
        else 
        return false ;
    }
    void generate(int oc , int cc ,string& s , int lim){
        if(s.size()==lim){
            if(isValid(s))
            ans.push_back(s);
            return ;
        }
        if(oc>0){
            s.push_back('(');
            generate(oc-1 , cc , s , lim);
            s.pop_back();
        }

        if(cc>0){
            s.push_back(')');
            generate(oc , cc-1 , s, lim);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int oc = n , cc = n ;
        string s ;
        generate(oc , cc , s , 2*n);
        return ans ; 

    }
};
