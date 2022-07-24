class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        vector<vector<int>> temp(grid.size(), vector<int> (grid[0].size(), 0));
        
        for(int i = 0; i < grid.size(); i++) {
            
            for(int j = 0; j < grid[0].size(); j++) {
                
                temp[j][i] = grid[i][j];
            }
        }
        
        int countPairs = 0;
        for(int i = 0; i < grid.size(); i++) {
            
          
            for(int j = 0; j < grid.size(); j++) {
                
                if(grid[i] == temp[j]) {
                    
                    countPairs++;
                }
            }
        }
        
        return countPairs;
    }
};