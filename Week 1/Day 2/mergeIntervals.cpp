class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for(int i = 0; i < n; i++) {
            
            vector<int> temp = ans.back();
            
            if(temp[1] >= intervals[i][0]) {
                
                if(temp[1] <= intervals[i][1]) {
                    
                    ans.pop_back();
                    ans.push_back({temp[0], intervals[i][1]});
                }
                
            } else {
                
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};