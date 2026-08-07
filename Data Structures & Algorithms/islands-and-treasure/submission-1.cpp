class Solution {
public:
    bool check(int i , int j , int m , int n){
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        return true ;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = INT_MAX; 
        int n = grid.size() ;
        int m = grid[0].size() ;
        queue<pair<int,int>>  q ;
        for(int i=0 ; i<n ;i++){
            for(int j=0 ; j<m;j++){
                if(grid[i][j]==0)
                q.push({i,j});
            }
        }
        int distance=1 ;
        while(!q.empty()){
            int size=q.size();
            while(size>0){
                auto it = q.front();
                q.pop();
                int i = it.first;
                int j = it.second ;
                int row[4] = {-1,1,0,0};
                int col[4] = {0,0,-1,1};

                for(int k=0;k<4;k++){
                    int r = i+row[k];
                    int c = j+col[k];

                    if (!check(r, c, m, n))
                      continue;
                    if(grid[r][c]==0)
                      continue ;
                    if(grid[r][c]==INF){
                        grid[r][c]=distance ;
                        q.push({r,c});
                    }
                }
                size -- ;
            }
            distance ++ ;
        }
    }
};
