class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        int maxSum = INT_MIN, minSum = INT_MAX, sum1 = 0, sum2 = 0, total = 0;
        
        for(int i = 0; i < n; i++) {
            
            total += nums[i];
            sum1 += nums[i];
            sum2 += nums[i];
            
            
            maxSum = max(maxSum, sum1);
            
            if(sum1 < 0)
                sum1 = 0;
            
            
            minSum = min(minSum, sum2);
            
            if(sum2 > 0)
                sum2 = 0;
        }
        
        if(total == minSum)
            return maxSum;
        
        return max(maxSum, total - minSum);
        
    }
};