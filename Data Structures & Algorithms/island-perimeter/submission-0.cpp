class Solution {
public:
    int dfs(vector<vector<int>>& grid , vector<vector<int>>& visit , int i , int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 )
        return 1 ;
        if(visit[i][j])
        return 0 ;
        visit[i][j]=1;
        int a = dfs(grid,visit,i+1,j);
        int b = dfs(grid,visit,i,j+1);
        int c = dfs(grid,visit,i,j-1);
        int d = dfs(grid,visit,i-1,j);
        int side = a +b+c+d ;
        return side ;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n , vector<int> (m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j =0 ; j<m ; j++){
                if(grid[i][j]==1){
                    return dfs(grid , visited , i ,j);
                    break ;
                }
            }
        }
        return 0 ;
    }
};