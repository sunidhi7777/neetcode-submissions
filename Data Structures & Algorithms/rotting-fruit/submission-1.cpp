class Solution {
public:
    bool check(int i , int j , int m , int n){
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        return true ;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q ;
        int n = grid.size();
        int m = grid[0].size();
        int i,j ,fresh =0 ;
        int minute = -1 ;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j] == 1)
                 fresh++;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(fresh == 0)
        return 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            if(check(r+1,c,m,n) && grid[r+1][c]==1){
                grid[r+1][c]=2;
                q.push({r+1,c});
            }
            if(check(r,c+1,m,n) && grid[r][c+1]==1){
                grid[r][c+1]=2;
                q.push({r,c+1});
            }
            if(check(r,c-1,m,n) && grid[r][c-1]==1){
                grid[r][c-1]=2;
                q.push({r,c-1});
            }
            if(check(r-1,c,m,n) && grid[r-1][c]==1){
                grid[r-1][c]=2;
                q.push({r-1,c});
            }
            }
            minute++ ;
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return minute ;
    }
};
