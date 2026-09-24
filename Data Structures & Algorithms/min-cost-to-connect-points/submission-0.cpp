class Solution {
public:
    int mdis(int i , int j , vector<vector<int>>& points){
        return abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n , false);
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;
        int cost = 0;
        pq.push({0,0}); // dis , point
        while(!pq.empty()){
            auto[ndis , node] = pq.top();
            pq.pop();
            if(!visited[node]){
                cost += ndis ;
                visited[node] = true ;
                for(int i = 0; i < n; i++){
                    if(!visited[i]){
                        int distance = mdis(node , i , points);
                        pq.push({distance,i});
                    }
                }
            }
        }
        return cost ;
    }
};
