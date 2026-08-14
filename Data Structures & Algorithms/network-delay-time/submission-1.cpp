class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> edges(n + 1);
        vector<int> distance(n+1 , INT_MAX) ; 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;

        for(int i=0 ; i<times.size() ; i++){
            edges[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        pq.push({0,k});
        distance[k] = 0;
        while(!pq.empty()){
            int src = pq.top().second ;
            int path = pq.top().first ;
            pq.pop();
            for(auto it : edges[src]){
                int dis = it.second;
                int node = it.first;
                if(distance[node]>dis+path){
                    distance[node] = dis + path;
                    pq.push({dis+path , node});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<n+1;i++){
            ans = max(ans, distance[i]);
            if(distance[i]==INT_MAX)
            return -1 ;
        }
        return ans ;

    }
};
