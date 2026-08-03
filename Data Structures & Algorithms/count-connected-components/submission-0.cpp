class Solution {
public:
    void dfs(int i , vector<vector<int>>& adj , vector<int>& visited ){
        if(visited[i])
        return ;
        visited[i]=1 ;
        for(int child : adj[i]){
            if(!visited[child])
            dfs( child , adj , visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,0);
        vector<vector<int>> adj(n);
        for(auto &it : edges){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int i , count = 0 ;
        for(i=0 ; i<n ; i++){
            if(!visited[i]){
                dfs( i , adj , visited);
                count++ ;
            }
        }
        return count ;
    }
};
