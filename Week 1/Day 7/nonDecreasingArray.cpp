class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        if(nums.size() < 2)
            return true;
        
        bool use = false;
        int last = -1e6;
        
        for(int i = 1; i < nums.size(); i++) {
            
            if(nums[i] < nums[i-1]) {
                
                if(use)
                    return false;
                
                if(nums[i] >= last)
                    nums[i-1] = nums[i];
                
                else 
                    nums[i] = nums[i-1];
                
                use = true;
            } 
            
            last = nums[i-1];
        }
        
        return true;
    }
};