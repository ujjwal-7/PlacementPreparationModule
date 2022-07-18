class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 2) {
            return {0, 1};
        }
        sort(nums.begin(), nums.end());
        
        int countOfPairs = 0;
        int i = 0;
        
        while(i < n - 1) {
            
            if(nums[i] == nums[i + 1]) {
                countOfPairs++;
                i += 2;
            } else {
                i++;
            }
        }
        
        return {countOfPairs, n - 2*countOfPairs};
        
    }
};