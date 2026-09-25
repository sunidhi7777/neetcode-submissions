/*
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n,INT_MAX);
        vector<int> stops(n,-1);
        vector<vector<pair<int,int>>> graph(n);
        for(int i = 0 ; i<flights.size() ; i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<tuple<int, int, int>> q ; 
        q.push({0,src,-1}); // distance , node , stops
        cost[src]=0;
        while(q.size() > 0){
            auto[ccost , p1 , stp] = q.front();
            q.pop();
            for(auto flight : graph[p1]){
                int cc = flight.second ;
                int p2 = flight.first ;
                if(stp+1 <= k && ccost+cc <= cost[p2]){
                    cost[p2] = ccost+cc ;
                    stops[p2] = stp+1 ;
                    q.push({cost[p2] , p2 , stops[p2]} ) ;
                }
            }
        }
        return cost[dst] ;
    }
};
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<int> cost(n, INT_MAX);

        vector<vector<pair<int,int>>> graph(n);

        for(int i = 0; i < flights.size(); i++) {
            graph[flights[i][0]].push_back(
                {flights[i][1], flights[i][2]}
            );
        }

        queue<int> q;
        q.push(src);

        cost[src] = 0;

        int stops = 0;

        while(!q.empty() && stops <= k) {

            int size = q.size();

            // IMPORTANT: don't update cost directly
            vector<int> nextCost = cost;

            while(size--) {

                int p1 = q.front();
                q.pop();

                for(auto flight : graph[p1]) {

                    int p2 = flight.first;
                    int cc = flight.second;

                    if(cost[p1] != INT_MAX &&
                       cost[p1] + cc < nextCost[p2]) {

                        nextCost[p2] = cost[p1] + cc;
                        q.push(p2);
                    }
                }
            }

            cost = nextCost;
            stops++;
        }

        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};