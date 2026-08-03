class Solution {
public:

    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& state) {

        if(state[node] == 1)
            return true;

        if(state[node] == 2)
            return false;

        state[node] = 1;

        for(int nei : adj[node]) {

            if(dfs(nei, adj, state))
                return true;
        }

        state[node] = 2;

        return false;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto& p : prerequisites) {

            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);
        }

        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {

            if(dfs(i, adj, state))
                return false;
        }

        return true;
    }
};