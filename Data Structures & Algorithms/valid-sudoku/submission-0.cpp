class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i , n , j ;
        for(i=0;i<9;i++){
            unordered_set<char> rmap ;
            unordered_set<char> cmap ;
            for(j=0;j<9;j++){
                char row , col ;
                row = board[i][j];
                col = board[j][i];
                if(row != '.') {

                    if(rmap.contains(row))
                        return false;

                    rmap.insert(row);
                }

                if(col != '.') {

                    if(cmap.contains(col))
                        return false;

                    cmap.insert(col);
                }
            }
        }
        for(i=0;i<9;i+=3){
            for(j=0;j<9;j+=3){
                int p , q ;
                unordered_set<char> rmap ;
                for(int p = 0; p < 3; p++) {
                for(int q = 0; q < 3; q++) {
                char row = board[p + i][q + j];
                if(row=='.')
                 continue ;
                if(rmap.contains(row))
                return false ;
                rmap.insert(row);
                }
                }
            }
        }
        return true ;
    }
};
