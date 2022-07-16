class Solution {
public:
    
    double helper(int n, int k, int row, int col, vector<vector<vector<double>>>& dp) {
        
        if(row < 0 || row >= n || col < 0 || col >= n)
            return 0;
        
        if(k == 0)
            return 1;
        
        if(dp[row][col][k] != -1)
            return dp[row][col][k];
        
        double p = 0;
        
        p += helper(n, k - 1, row - 2, col - 1, dp);
        p += helper(n, k - 1, row - 2, col + 1, dp);
        p += helper(n, k - 1, row - 1, col - 2, dp);
        p += helper(n, k - 1, row - 1, col + 2, dp);
        p += helper(n, k - 1, row + 1, col - 2, dp);
        p += helper(n, k - 1, row + 1, col + 2, dp);
        p += helper(n, k - 1, row + 2, col - 1, dp);
        p += helper(n, k - 1, row + 2, col + 1, dp);
        
        return dp[row][col][k] = p / 8;
        
    }
    
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n , vector<double> (k+1, -1)));
        return helper(n, k, row, column, dp);
    }
};