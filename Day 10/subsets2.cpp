class Solution {
public:
    
    void generateSubsets(int i, vector<int>& nums, vector<int> temp, vector<vector<int>>&ans) {
        ans.push_back(temp);
        
        for(int j = i; j < nums.size(); j++) {
            
            if(j > i && nums[j] == nums[j-1])
                continue;
            
            temp.push_back(nums[j]);
            generateSubsets(j + 1, nums, temp, ans);
            temp.pop_back();
            
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        generateSubsets(0, nums, temp, ans);
        
        return ans;
        
    }
};