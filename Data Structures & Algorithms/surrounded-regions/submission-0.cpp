class Solution {
public:
    void capture(vector<vector<char>>& board , vector<vector<bool>>& visited , int i , int j ){
        int n = board.size();
        int m = board[0].size();
        if(i<0 || i>= n || j<0 || j>=m || visited[i][j] || board[i][j] == 'X')
        return ;
        visited[i][j] = true ;
        board[i][j] = 'X' ;
        capture(board , visited , i+1 , j ); 
        capture(board , visited , i-1 , j ); 
        capture(board , visited , i , j+1 ); 
        capture(board , visited , i , j-1 ); 
    }
    void dfs(vector<vector<char>>& heights , vector<vector<bool>>& visited , int i , int j ){
        int n = heights.size();
        int m = heights[0].size();
        if(i<0 || i>= n || j<0 || j>=m || visited[i][j] || heights[i][j] == 'X')
        return ;
        visited[i][j] = true ;
        dfs(heights , visited , i+1 , j ); 
        dfs(heights , visited , i-1 , j ); 
        dfs(heights , visited , i , j+1 ); 
        dfs(heights , visited , i , j-1 ); 
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int i , j ;
        for(int i = 0; i < n; i++) {

            if(board[i][0] == 'O')
                dfs(board, visited, i, 0);

            if(board[i][m - 1] == 'O')
                dfs(board, visited, i, m - 1);
        }

        // top + bottom borders
        for(int j = 0; j < m; j++) {

            if(board[0][j] == 'O')
                dfs(board, visited, 0, j);

            if(board[n - 1][j] == 'O')
                dfs(board, visited, n - 1, j);
        }
        for(i=1;i<n-1;i++){
            for(j=1;j<m-1;j++){
                if(board[i][j] == 'O' && !visited[i][j])
                 board[i][j] = 'X';
            }
        }
    }
};
