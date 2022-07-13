class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        int count = 1, element = nums[0];
        
        for(int i = 1; i < n; i++) {
            
            if(nums[i] == element) {
                count++;
            } else {
                count--;
                if(count == 0) {
                    
                    count =1;
                    element = nums[i];
                }
                
            }
        }
        
       return element;
    }
};