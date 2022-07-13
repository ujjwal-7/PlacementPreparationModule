class Solution {
public:
    
    void generateSubsets(int i, vector<int> temp, vector<int>& nums, vector<vector<int>>& ans) {
    
        ans.push_back(temp);
           
        
        for(int start = i; start < nums.size(); start++) {
            
            temp.push_back(nums[start]);
            generateSubsets(start + 1, temp, nums, ans);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        generateSubsets(0, temp, nums, ans);
        return ans;
    }
};