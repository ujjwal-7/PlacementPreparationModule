class Solution {
public:
    
    int helper(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>>& dp) {
        
        if(startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n)
            return 1;
        
        if(maxMove == 0)
            return 0;
        
        if(dp[startRow][startColumn][maxMove] != -1)
            return dp[startRow][startColumn][maxMove];
        
        int ans = 0;
        
        ans = (ans + helper(m, n, maxMove - 1, startRow + 1, startColumn, dp)) % 1000000007;
        ans = (ans + helper(m, n, maxMove - 1, startRow - 1, startColumn, dp)) % 1000000007;
        ans = (ans + helper(m, n, maxMove - 1, startRow, startColumn + 1, dp)) % 1000000007;
        ans = (ans + helper(m, n, maxMove - 1, startRow, startColumn - 1, dp)) % 1000000007;
        
        return dp[startRow][startColumn][maxMove] = ans % 1000000007;
        
    }   
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
       vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (maxMove + 1, -1)));
       return helper(m, n, maxMove, startRow, startColumn, dp);
    }
};