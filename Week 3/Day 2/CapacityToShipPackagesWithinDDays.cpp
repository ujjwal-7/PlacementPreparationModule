class Solution {
public:
    
    bool isPossible(vector<int>& weights, int days, int mid) {
        
        int sum = 0, d = 1;
        for(int i = 0; i <weights.size(); i++) {
            
            sum += weights[i];
            
            if(sum > mid) {
                sum = weights[i];
                d++;
            }
            
            if(d > days)
                return false;
            
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = 0, high = 0, capacity = 0;
        
        for(int i = 0; i < weights.size(); i++) {
            
            low = max(low, weights[i]);
            high += weights[i];
        }
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            
            if(isPossible(weights, days, mid)) {
                
                capacity = mid;
                high = mid - 1;
                
            } else {
                low = mid + 1;
            }
        }
        
        return capacity;
    }
};