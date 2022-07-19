class Solution {
public:
    
    bool isPossible(vector<int>& piles, int mid, int h) {
        
        int hours = 0;
        
        for(int i = 0; i < piles.size(); i++) {
            
            hours += piles[i] / mid;
            
            if(piles[i] % mid != 0)
                hours += 1;
                
            if(hours > h)
                return false;
        }
        
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1, high = 0, speed = 1;
        
        for(int i = 0; i < piles.size(); i++) {
            
            high  = max(high, piles[i]);
        }
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            
            if(isPossible(piles, mid, h)) {
                
                speed = mid;
                high = mid - 1;
            } else {
                
                low = mid + 1;
            }
        }
        
        return speed;
        
    }
};