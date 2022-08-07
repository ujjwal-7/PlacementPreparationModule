class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        
        long long int numberOfBadPairs = 0;
        
        for(int i = 0; i < n; i++) {
            mp[i - nums[i]] += 1;
        }
        
    
        for(int i = 0; i < n; i++) {
            
            mp[i - nums[i]] -= 1;
            numberOfBadPairs += n - 1 - i - mp[i - nums[i]];
            
        }
        
        return numberOfBadPairs;
    }
};