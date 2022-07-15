class Solution {
public:
    
    void permute(vector<int>& nums, int start, int end, vector<vector<int>>& ans) {
        
        if(start > end) {
            
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> s;
        for(int i = start; i <= end; i++) {
            
            if(s.find(nums[i]) != s.end())
                continue;
            
            s.insert(nums[i]);
            swap(nums[start], nums[i]);
            permute(nums, start + 1, end, ans);
            swap(nums[start], nums[i]);
            
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        permute(nums, 0, nums.size() - 1, ans);
        
        return ans;
    }
};