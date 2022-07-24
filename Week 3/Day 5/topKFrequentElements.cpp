class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++) {
            
            mp[nums[i]]++;
        }
        
        vector<vector<int>> temp(nums.size() + 1);
        
        for(auto it: mp) {
            
            temp[it.second].push_back(it.first);
        }
        
        
        vector<int> ans;
        
        for(int i = nums.size(); i >= 0 && ans.size() < k; i--) {
            
            for(int j = 0; j < temp[i].size(); j++)
                ans.push_back(temp[i][j]);
        }
        
        return ans;
    }
};