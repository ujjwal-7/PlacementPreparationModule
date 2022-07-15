class Solution {
public:
    
    bool isSafe(vector<string>& board, int row, int col, int n) {
        
        int i = row - 1, j = col - 1;
        
        while(i >= 0 && j >= 0) {
            
            if(board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        
        i = row, j = col - 1;
        
        while(i >= 0 && j >= 0) {
            
            if(board[i][j] == 'Q')
                return false;
            j--;
        }
        
        i = row + 1, j = col - 1;
        
        while(i < n && j >= 0) {
            
            if(board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }
        
        return true;
        
    }
    
    void placeQueens(vector<string>& board, int col, int n, vector<vector<string>>& ans) {
        
        if(col == n) {
            ans.push_back(board);
            return;
        }
        
        
        for(int row = 0; row < n; row++) {
            
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                placeQueens(board, col + 1, n, ans);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n);
        
        string temp(n, '.');
        
        for(int i=0; i<n; i++) {
            
           board[i] = temp;
        }
        
        
        placeQueens(board, 0, n, ans);        
        return ans;
    }
};