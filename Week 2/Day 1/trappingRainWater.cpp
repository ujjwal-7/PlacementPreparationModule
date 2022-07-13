class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
         if(n <= 2)
            return 0;
        
        int leftMax = height[0], rightMax = height[n - 1];
        int l = 1, r = n - 2, ans = 0;
        
        while(l <= r) {
            
            if(leftMax <= rightMax) {
                
                if(height[l] > leftMax)
                    leftMax = height[l];
                else {
                    
                    ans += leftMax - height[l];
                   l++;
                }
                 
            } else {
                
                if(height[r] > rightMax)
                    rightMax = height[r];
                else {
                    
                    ans += rightMax - height[r];
                    r--;
                }
            }
        }
        
        return ans;
    }
};