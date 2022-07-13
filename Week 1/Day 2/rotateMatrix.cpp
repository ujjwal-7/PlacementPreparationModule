class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for(int row = 0; row < n ; row++) {
            
            for(int col = 0; col < n; col++) {
                
                if(row == col || row < col) {
                    swap(matrix[row][col], matrix[col][row]);
                }
            }
        }
        
        for(int row = 0; row < n; row++) {
            
            reverse(matrix[row].begin(), matrix[row].end());
        }
        
        
    }
};