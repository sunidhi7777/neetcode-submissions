class Solution {
public:
    bool dfs(int i , vector<vector<int>>& adj , vector<int>& visit , stack<int>& stk ){
        if(visit[i] == 1)
        return true ;

        if(visit[i] == 2)
        return false ;

        visit[i] = 1 ;
        for(int child : adj[i]){
           if( dfs(child , adj , visit , stk ) )
           return true; 
        }

        visit[i] = 2 ;
        stk.push(i);
        return false ;

    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(n) ;
        stack<int> stk ;
        vector<int> visit(n,0);
        for(auto &p :prerequisites){
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
        }
        int i ;
        for(i = 0 ;i<n;i++){
            if(dfs(i , adj , visit , stk ))
            return {};
           }
        for(i=0 ; i<n ; i++){
                visit[i] = stk.top();
                stk.pop();
        }
        return visit ; 
    }
};
