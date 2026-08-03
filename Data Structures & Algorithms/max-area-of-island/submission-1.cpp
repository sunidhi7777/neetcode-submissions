class Solution {
public:
    int dfs(vector<vector<int>>& grid , int count , int i , int j){
        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || j<0 || i>= n || j>= m || grid[i][j]==0)
        return 0 ;

        if(grid[i][j]==1){
            grid[i][j]=0 ;
            count =1+ dfs(grid , count ,i+1 ,j) + dfs(grid , count ,i-1 ,j) + dfs(grid , count ,i ,j+1) + dfs(grid , count ,i ,j-1);
        }
        return count ;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0,maxarea =0 , area ;
        int i , j ;
        int n = grid.size();
        int m = grid[0].size();
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]==1){
                    area = dfs(grid , 0 , i ,j);
                    maxarea = max(area,maxarea);
                }
            }
        }
        return maxarea ;
    }
};
