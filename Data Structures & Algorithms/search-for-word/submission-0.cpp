class Solution {
public:

    bool find(vector<vector<char>>& board, string word, int i,  int j, int p) {

        if(p == word.size())
            return true;

        int n = board.size();
        int m = board[0].size();

        if(i < 0 || i >= n ||
           j < 0 || j >= m ||
           board[i][j] != word[p])
            return false;

        char temp = board[i][j];

        board[i][j] = '#';

        bool found =
            find(board, word, i + 1, j, p + 1) ||
            find(board, word, i - 1, j, p + 1) ||
            find(board, word, i, j + 1, p + 1) ||
            find(board, word, i, j - 1, p + 1);

        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(board[i][j] == word[0]) {

                    if(find(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};
