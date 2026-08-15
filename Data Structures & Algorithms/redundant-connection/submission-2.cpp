class Solution {
public:
    vector<int> parent ;
    int find(int val){
        if(parent[val]==val){
            return val ;
        }
        return parent[val] = find(parent[val]);
    }
    bool unite(int v1 , int v2){
        int p1 = find(v1);
        int p2 = find(v2);
        if(p1==p2)
        return false ;
        parent[p2] = p1 ;
        return true ;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for(int i=1 ; i<=n ; i++){
            parent[i] = i ;
        }
        for(auto edge : edges){
            int p1 = edge[0];
            int p2 = edge[1];
            if(!unite(p1,p2))
            return edge ;
        }
        return {} ;
    }
};
