class Solution {
public:
    int solve(string& s, string&t, int m, int n, vector<vector<int>>& dp) {
        
        if(m == 0 || n == 0) {
            return n == 0 ? 1 : 0;
        }
        
        if(dp[m][n] != -1) {
            return dp[m][n];
        }
        
        if(s[m - 1] == t[n - 1]) {
            return dp[m][n] = solve(s, t, m - 1, n - 1, dp) + solve(s, t, m - 1, n, dp);
        }
        
        return dp[m][n] = solve(s, t, m - 1, n, dp);
    }
    
    int numDistinct(string s, string t) {
        
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
       // return solve(s, t, m, n, dp);
        
        for(int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        
       for(int i = 1; i <= m; i++) {
           
           for(int j = 1; j <= n; j++) {
               
               if(s[i - 1] == s[j - 1]) {
                   dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
               } else {
                   dp[i][j] = dp[i - 1][j];
               }
           }
        }
        return dp[m][n];
    }
};