class Solution {
public:
    int solve(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
      
        
        if(i == nums.size()) {
            
            if(target == 0)
                return 1;
        
            return 0;
        }
        
        if(dp[i][target] != -1)
            return dp[i][target];
        
        int include = 0, exclude = 0;
        if(nums[i] <= target) {
            include = solve(nums, 0, target - nums[i], dp);
        }
        exclude = solve(nums, i + 1, target, dp);
        
        return dp[i][target] = include + exclude;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        int i = 0;
        vector<vector<int>> dp(nums.size() + 1, vector<int> (target + 1, - 1));
        
        return solve(nums, i, target, dp);
    }
};