class Solution {
public:
    bool valid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m )
        return false ;
        return true ;
    }
    int swimInWater(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> time(n , vector<int>(m , INT_MAX));
        priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> pq ;
        time[0][0] = 0 ;
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            auto[level , i , j] = pq.top();
            pq.pop();
            int p[] = {1,-1,0,0};
            int q[] = {0,0,1,-1};
            for(int k = 0 ; k<4 ; k++){
                int r = i + p[k];
                int c = j + q[k];
                if(valid(r,c,n,m)){
                    int val = grid[r][c];
                    int height = max(val , level);
                    if(height<time[r][c]){
                        time[r][c] = height ;
                        pq.push({height , r , c});
                    }
                    
                }
            }
        }
        return time[n-1][m-1];
    }
};
