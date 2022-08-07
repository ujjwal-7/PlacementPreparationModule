class Solution {
public:
    int helper(int i, int j, int m, int n) {
        
        if(i == m - 1 && j == n - 1) {
            return 1;
        }
        
        if(i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }
        
        return helper(i + 1, j, m, n) + helper(i, j + 1, m, n);
    }
    
    int uniquePaths(int m, int n) {
        
        //return helper(0, 0, m, n);
        
        vector<vector<int>> dp(m, vector<int> (n, 1));
        
        for(int i = 1; i < m; i++) {
            
            for(int j = 1; j < n; j++) {
                
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
    
};