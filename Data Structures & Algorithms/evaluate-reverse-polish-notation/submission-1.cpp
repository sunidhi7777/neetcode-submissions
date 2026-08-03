class Solution {
public:
    int calc(int a, int b, char op)
   {
    if(op == '+')
        return a + b;

    if(op == '-')
        return a - b;

    if(op == '*')
        return a * b;

    if(op == '/')
        return a / b;

    return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st ;
        for(string token : tokens) {

            if(token == "+" ||
               token == "-" ||
               token == "*" ||
               token == "/") {

                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                st.push(calc(a, b, token[0]));
            }
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
