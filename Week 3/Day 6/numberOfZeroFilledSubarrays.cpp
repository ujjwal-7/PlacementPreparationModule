class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        
        long long  subarrays = 0;
        long long consecutiveZeros = 0;
        
        
        for(int i = 0; i < nums.size(); i++) {
            
            if(nums[i] == 0) {
                
                consecutiveZeros += 1;
                
            } else {
                
                subarrays += (consecutiveZeros * (consecutiveZeros + 1)) / 2;
                consecutiveZeros  = 0;
            }
        }
        
       
        subarrays += (consecutiveZeros * (consecutiveZeros + 1)) / 2;
        return subarrays;
        
    }
};