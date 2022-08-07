class Solution {
public:
    int solve(int n, char prev, unordered_map<char, vector<char>>& mp, unordered_map<char, vector<int>>& dp) {
        
        if(n == 0)
            return 1;
        
        if(dp[prev][n])
            return dp[prev][n];
    
        for(auto it: mp[prev]) {
            dp[prev][n]  = (dp[prev][n]  + solve(n - 1, it, mp, dp)) % 1000000007;
        }
        return dp[prev][n];
    }
    
    
    int countVowelPermutation(int n) {
        
        unordered_map<char, vector<char>> mp = {
            {'s', {'a', 'e', 'i', 'o', 'u'}},
            {'a', {'e'}}, 
            {'e', {'a', 'i'}}, 
            {'i', {'a', 'e', 'o', 'u'}}, 
            {'o', {'i', 'u'}},
            {'u', {'a'}}
        };
        
        unordered_map<char, vector<int>> dp;
        dp['s'] = dp['a'] = dp['e'] = dp['i'] = dp['o'] = dp['u'] = vector<int> (n + 1);
        
        return solve(n, 's', mp, dp);
    }
};