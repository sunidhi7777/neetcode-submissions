/*class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<char> rank(26);
        int n = words.size();
        int length = words[0].size();
        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }
        for(int i = i ; i<n , i++){
            if(words[i].length()<words[i-1].length())
            return false ;
            length = max(length , words[i].length());
        }
        for(int i =0 ; i<length ; i++){
            int highest = rank(words[i][j]);
            for(int j = 0 ; j<n ; j++){
                if(word)
                if(rank(words[i][j])<highest)
                return false ;
                highest = max(rank(words[i][j]) , highest);
            }
        }
    }
};
*/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        // rank[c] = position of character c in alien alphabet
        vector<int> rank(26);

        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }

        // Compare every adjacent pair
        for (int i = 0; i < words.size() - 1; i++) {
            
            string word1 = words[i];
            string word2 = words[i + 1];

            int j = 0;

            // Compare characters while both words have characters
            while (j < word1.size() && j < word2.size()) {

                if (word1[j] != word2[j]) {

                    // word1's character comes after word2's
                    if (rank[word1[j] - 'a'] > rank[word2[j] - 'a']) {
                        return false;
                    }

                    // First different character determines the ordering
                    break;
                }

                j++;
            }

            // All characters matched, so check prefix case
            if (j == word2.size() && j < word1.size()) {
                return false;
            }
        }

        return true;
    }
};