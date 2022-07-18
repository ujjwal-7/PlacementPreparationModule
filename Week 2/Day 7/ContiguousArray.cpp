class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        int maxLength = 0;
        
        unordered_map<int, int> mp;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            
            
            if(nums[i] == 1)
                sum += 1;
            else
                sum -= 1;
            
            if(sum == 0)
                maxLength = max(maxLength, i + 1);
            
            if(mp.find(sum) != mp.end()) {
                
                maxLength = max(maxLength, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
            
        }
        
        return maxLength;
    }
};