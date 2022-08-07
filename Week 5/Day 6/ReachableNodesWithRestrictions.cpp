class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, unordered_set<int>& s, int& count, vector<int>& vis) {
        
        if(s.find(i) != s.end() || vis[i] == 1) {
            return;
        }
        
        vis[i] = 1;
        count++;
        
        for(auto it : adj[i]) {
            if(vis[it] == 0)
                dfs(it, adj, s, count, vis);
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        unordered_set<int> s;
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        
        for(int i = 0; i < edges.size(); i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0; i < restricted.size(); i++) {
            s.insert(restricted[i]);
        }
        
        int count = 0;
        dfs(0, adj, s, count, vis);
        return count;
        
    }
};