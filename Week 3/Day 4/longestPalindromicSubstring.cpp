class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        int start = -1, end = -1;
        
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        
        for(int gap = 0; gap < n; gap++) {
            
            for(int i = 0, j = gap; j < n; i++, j++) {
                
                if(gap == 0) {
                    
                    dp[i][j] = true;
                } else if(gap == 1) {
                    
                    if(s[i] == s[j]) {
                        
                        dp[i][j] = true;  
                    } else {
                        
                        dp[i][j] = false;
                    } 
                } else {
                    
                    if(s[i] == s[j] && dp[i + 1][j - 1] == true) {
                        
                        dp[i][j] = true;
                    } else {
                        
                        dp[i][j] = false;
                    }    
                }
                
                if(dp[i][j]) {
                    
                    start = i;
                    end = j;
                }
            }
        }
        if(start == -1 || end == -1)
            return "";
        
        string ans = "";
        for(int k = start; k <= end; k++)
            ans += s[k];
        
        return ans;
    }
};