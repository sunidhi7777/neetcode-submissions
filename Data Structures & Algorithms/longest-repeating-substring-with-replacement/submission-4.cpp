class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0 , ans = 0 , maxfreq = 0 ;
        vector<int> count(26,0);
        for(int right = 0 ; right<s.size() ; right++){
            count[s[right] - 'A'] ++ ;
            maxfreq = max(maxfreq , count[s[right] - 'A'] );
            while ((right - left + 1) - maxfreq > k) {
            count[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans ;
    }
};
