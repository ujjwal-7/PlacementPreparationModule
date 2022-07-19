class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int threshold) {
        
        int sum = 0;
        
        for(int i = 0; i< nums.size(); i++) {
            
            if(nums[i] % mid == 0)
                sum += nums[i] / mid;
            else
                sum += nums[i] / mid + 1;
            
            if(sum > threshold)
                return false;
        }
        
        return true;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1, high = 0, divisor = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            high = max(high, nums[i]);
        }
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            
            if(isPossible(nums, mid, threshold)) {
                
                divisor = mid;
                high = mid - 1;
            } else {
                
                low = mid + 1;
            }
        }
        
        return divisor;
    }
};