class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph, vector<int>& state, stack<int>& order){
        if(state[i]==1)
        return false ;
        if(state[i]==2)
        return true ;
        state[i]=1 ;
        bool ans = true ;
        for(auto c : graph[i]){
            ans &= dfs(c, graph, state, order);
        }
        state[i] = 2 ;
        order.push(i);
        return ans ;
    }
    string foreignDictionary(vector<string>& words) {
        vector<int> state(26, 0); 
        vector<bool> present(26, false);
        vector<vector<int>> maps(26);
        int n = words.size();
        for (string& word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }
        stack<int> order ;
        for(int i = 0 ; i<n-1 ; i++){
            string a = words[i];
            string b = words[i+1];
            int len = min(a.size(), b.size());
            int j = 0;
            while(j < len && a[j] == b[j]){
                j++ ;
            }
            if(j==len && a.size()>b.size())
            return "";
            if (j < len) {
    int p = a[j] - 'a';
    int q = b[j] - 'a';

    maps[p].push_back(q);
}
        }
        for (int i = 0; i < 26; i++) {
            if (present[i] && state[i] == 0) {
                if (!dfs(i, maps, state, order)) {
                    return "";
                }
            }
        }
        string ans ;
        while(!order.empty()){
            char d = order.top()+'a' ;
            ans.push_back(d);
            order.pop();
        }
        return ans ;
    }
};
