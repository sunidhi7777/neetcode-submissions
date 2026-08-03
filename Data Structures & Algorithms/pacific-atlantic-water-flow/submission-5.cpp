class Solution {
public:
    void dfs(vector<vector<int>>& heights , vector<vector<bool>>& visited , int i , int j , int val){
        int n = heights.size();
        int m = heights[0].size();
        if(i<0 || i>= n || j<0 || j>=m || heights[i][j] < val || visited[i][j])
        return ;
        visited[i][j] = true ; 
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        for(int k = 0; k < 4; k++) {

    int ni = i + dr[k];
    int nj = j + dc[k];

    if(ni >= 0 && ni < n &&
       nj >= 0 && nj < m &&
       !visited[ni][nj] &&
       heights[ni][nj] >= heights[i][j]) {

        dfs(heights, visited, ni, nj, heights[i][j]);
    }
}
        /*
        dfs(heights , visited , i+1 , j , heights[i][j]); 
        dfs(heights , visited , i-1 , j , heights[i][j]); 
        dfs(heights , visited , i , j+1 , heights[i][j]); 
        dfs(heights , visited , i , j-1 , heights[i][j]); 
        */
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans ;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        int i , j ;
        for(i=0;i<m;i++){
            dfs(heights , pacific , 0 , i , 0);
        }
        for(i=1;i<n;i++){
            dfs(heights , pacific , i , 0 ,0);
        }
        for(i=0;i<m;i++){
            dfs(heights , atlantic , n-1 , i ,0);
        }
        for(i=0;i<n;i++){
            dfs(heights , atlantic , i , m-1 , 0);
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(pacific[i][j] == true && atlantic[i][j] == true )
                ans.push_back({i,j});
            }
        }
        return ans;
    }
};
