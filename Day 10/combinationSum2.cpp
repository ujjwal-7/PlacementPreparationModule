class Solution {
public:
    
    void solve(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int target) {
        

        if(target == 0) 
            ans.push_back(temp);
        
        if(target < 0)
            return;
          
        
        for(int j = i; j < nums.size(); j++) {
            
            if(j > i && nums[j] == nums[j-1])
                continue;
            
            temp.push_back(nums[j]);
            solve(j + 1, nums, temp, ans, target - nums[j]);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0, candidates, temp, ans, target);
        
        return ans;
    }
};