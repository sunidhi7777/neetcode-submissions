class Solution {
public:
    bool valid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m )
        return false ;
        return true ;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int im = INT_MAX;
        vector<vector<int>> distance(n , vector<int> (m, im));
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;
        pq.push({0,0,0});
        distance[0][0]=0 ;
        while(!pq.empty()){
            auto [path , i, j] = pq.top();
            pq.pop();
            int p[] = {1,-1,0,0};
            int q[] = {0,0,1,-1};
            for(int k = 0 ; k<4 ; k++){
                int r = i + p[k];
                int c = j + q[k];
                if(valid(r,c,n,m)){
                    int diff = abs(heights[i][j] - heights[r][c]);
                    int newEffort = max(path, diff);
                    if(newEffort < distance[r][c]) {
                       distance[r][c] = newEffort;
                       pq.push({newEffort, r, c});
                    }
                }
            }

        }
        return distance[n-1][m-1];
    }
};