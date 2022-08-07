class Solution {
public:
    
    int solve(string word1, string word2, int n, int m, vector<vector<int>>& dp) {
        
        if(n == 0 || m == 0) {
            return n == 0 ? m : n;
        }
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(word1[n - 1] == word2[m - 1]) {
            return dp[n][m] = solve(word1, word2, n - 1, m - 1, dp);
        } 
        return dp[n][m] = 1 + min(solve(word1, word2, n - 1, m - 1, dp), min(solve(word1, word2, n - 1, m, dp), solve(word1, word2, n, m - 1, dp)));
    }
    
    int minDistance(string word1, string word2) {
        
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        //return solve(word1, word2, n, m, dp);
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = i;
        
        for(int j = 0; j <= m; j++)
            dp[0][j] = j;
        
        for(int i = 1; i <= n; i++) {
            
            for(int j = 1; j <= m; j++) {
                
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])); 
                }
            }
        }
        return dp[n][m];
    }
};