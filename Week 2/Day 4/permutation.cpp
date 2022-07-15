class Solution {
public:
    
    void findPermutations(vector<int>& nums, int start, int end, vector<vector<int>>& ans) {
        
        if(start == end) {
            ans.push_back(nums);
        }
        
        for(int i = start; i <= end; i++) {
            
            swap(nums[start], nums[i]);
            findPermutations(nums, start + 1, end, ans);
            swap(nums[start], nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
      
        vector<vector<int>> ans;
        findPermutations(nums, 0, n - 1, ans);
        return ans;
    }
};