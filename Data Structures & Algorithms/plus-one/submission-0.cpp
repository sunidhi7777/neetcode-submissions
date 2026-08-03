class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i , n = digits.size();
        // digits[n-1] += 1 ;
        int carry = 1 ;
        for(i=n-1;i>=0;i--){
            digits[i] += carry ;
            if(digits[i]>9){
                carry = 1 ;
                digits[i] = 0 ;
            }else{
                carry = 0 ;
                break ;
            }
        }
        if(carry==1){
            digits.insert(digits.begin(), 1);
        }
        return digits ;
    }
};
