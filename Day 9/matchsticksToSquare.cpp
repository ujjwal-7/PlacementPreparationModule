class Solution {
public:
    
    bool partition(vector<int>& matchsticks, vector<bool>& visited, int n, int ind, int curSum, int target, int k){
        
        if(k==0)
            return true;
        
        if(curSum == target)
            return partition(matchsticks, visited, n, 0, 0, target, k-1);
        
        for(int i = ind; i<n; i++) {
            if(visited[i] == true || matchsticks[i] + curSum > target) 
                continue;

                visited[i] = true;
                if(partition(matchsticks, visited, n, i+1, curSum+matchsticks[i], target, k))
                    return true;
                visited[i] = false;
                  
        }
        return false;
        
    }
    
    bool makesquare(vector<int>& matchsticks) {
       
        int sum = 0, n = matchsticks.size();
        
        for(int i = 0; i<n; i++)
            sum += matchsticks[i];
        
        if(n<4 || sum%4 != 0)
            return false;
 
        vector<bool> visited (n, false);
        
        return partition(matchsticks, visited, n, 0, 0, sum/4, 4);
    }
};