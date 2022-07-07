class Solution {
public:
    
    string solve(string& s, int& pos, int n) {
        
        int num = 0;
        string word = "";
        
        while(pos < n) {
            
            
            if(s[pos] == '[') {
                
                pos++;
                string curString = solve(s, pos, n);
                
                while(num > 0) {
                    word += curString;
                    num--;
                }
                    
                
            } else if(s[pos] >= '0' && s[pos] <= '9') {
                
                num = num*10 + s[pos] - '0';
                
            } else if(s[pos] == ']') {
                
                return word;
                
            } else {
                
                word += s[pos];
            }
            
            pos++;
        }
        return word;
    }
    
    string decodeString(string s) {
        
       int n = s.size();
        int pos = 0;
        return solve(s, pos, n);
    }
};