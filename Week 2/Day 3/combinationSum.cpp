class Solution {
public:
    
    void solve(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int target) {
        
        if(i == nums.size()) {
            
            if(target == 0) {
                ans.push_back(temp);
            }
            
            return;
        }
        
        if(nums[i] <= target) {
            
            temp.push_back(nums[i]);
            solve(i, nums, temp, ans, target - nums[i]);
            temp.pop_back();
            
        }
        
        solve(i+1, nums, temp, ans, target);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0, candidates, temp, ans, target);
        
        return ans;
        
    }
};