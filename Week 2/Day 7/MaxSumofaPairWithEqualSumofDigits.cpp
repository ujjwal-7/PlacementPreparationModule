class Solution {
public:
    
    int calcSum(int a) {
        
        int sum1 = 0;
        
        while(a > 0) {
            
            int rem1 = a % 10;
            sum1 += rem1;
            a /= 10;
        }
        
       
        return sum1;
    }
    
    int maximumSum(vector<int>& nums) {
        
        int n = nums.size();
        int maxSum = -1;
        
        sort(nums.rbegin(), nums.rend());
        
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < n; i++) {
            
            int sum = calcSum(nums[i]);
            mp[sum].push_back(nums[i]);
        }
        
        
        for(auto it: mp) {
            
            if(it.second.size() >= 2) {
                maxSum = max(maxSum, it.second[0] + it.second[1]);
            }
        }
        
        return maxSum;
    }
};