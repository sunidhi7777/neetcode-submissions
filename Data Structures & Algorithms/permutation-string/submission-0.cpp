/*class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
    }
};*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 > n2)
            return false;

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        for(char ch : s1) {
            need[ch - 'a']++;
        }

        for(int i = 0; i < n1; i++) {
            window[s2[i] - 'a']++;
        }

        if(need == window)
            return true;

        for(int i = n1; i < n2; i++) {

            // add new character
            window[s2[i] - 'a']++;

            // remove old character
            window[s2[i - n1] - 'a']--;

            if(need == window)
                return true;
        }

        return false;
    }
};