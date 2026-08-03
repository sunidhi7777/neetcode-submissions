class Solution {
public:
    bool dfs(int child , int parent ,vector<vector<int>>& adj ,vector<int>& visited ){
        visited[child] = true ;
        bool x = true ;
        int i ;
        for(int i : adj[child]){
            if(visited[i]==true && i==parent)
            continue ;
            if(visited[i]==true)
            return false ;
            x &= dfs(i , child , adj , visited);
        }
        return x ;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n-1 != edges.size())
        return false ;
        vector<int> visited(n,0);
        vector<vector<int>> adj(n);

        for(auto &it : edges){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool valid = dfs(0 , -1 , adj , visited );
        int i;
        for(i=0 ; i<n ; i++){
            if(!visited[i])
            return false ;
        }
        return true ;
    }
};
