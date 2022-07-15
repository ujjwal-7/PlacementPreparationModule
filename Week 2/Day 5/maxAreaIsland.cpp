class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& vis) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || vis[i][j] == 1)
            return 0;
        
        vis[i][j] = 1;
        
        int area = 1;
        
        area += dfs(grid, i + 1, j, m, n, vis);
        area += dfs(grid, i - 1, j, m, n, vis);
        area += dfs(grid, i, j + 1, m, n, vis);
        area += dfs(grid, i, j - 1, m, n, vis);
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;
        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        for(int i = 0; i < m; i++) {
            
            for(int j = 0; j < n; j++) {
                
                if(grid[i][j] == 1 && vis[i][j] != 1)
                    maxArea = max(maxArea, dfs(grid, i, j, m, n, vis));
            }
        }
        
        return maxArea;
    }
};