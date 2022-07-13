class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        
       int n = nums.size();
       if(n == 0)
           return 0;
        
       unordered_set<int> s;
        
        for(int i = 0; i < n; i++)
            s.insert(nums[i]);
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(s.find(nums[i] - 1) == s.end()) {
                
                int count = 1;
                int cur = nums[i];
                
                while(s.find(cur + 1) != s.end())  {
                    
                    count += 1;
                    cur += 1;
                }
                    
                
                ans = max(ans, count);
            }
        }
        
        return ans;
    }
};