class Solution {
public:
    
    bool isPossible(vector<int>& bloomDay, int m, int k, int days) {
        
        int flowers = 0, bouquets = 0;
        
        for(int i = 0; i < bloomDay.size(); i++) {
            
            if(bloomDay[i] <= days) {
                flowers++;
            } else {
                flowers = 0;
            }
            
            if(flowers == k) {
                bouquets++;
                flowers = 0;
            }
            
            if(bouquets == m)
                return true;
            
        }
        
        return false;
        
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int low = 1, high = 0, days = -1;
        
        for(int i = 0; i < bloomDay.size(); i++) {
            
            high = max(high, bloomDay[i]);
        }
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            
            if(isPossible(bloomDay, m, k, mid)) {
                
                days = mid;
                high = mid - 1;
                
            } else {
                low = mid + 1;
            }
        }
        
        return days;
        
    }
};