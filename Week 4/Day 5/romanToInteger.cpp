class Solution {
public:
    int findValue(char ch) {
        
        switch(ch) {
                
            case 'I' : return 1;
            
            case 'V' : return 5;
                
            case 'X' : return 10;
                
            case 'L' : return 50;
                
            case 'C' : return 100;
                
            case 'D' : return 500;
                
            case 'M' : return 1000;
        }
        
        return 0;
    }
    
    int romanToInt(string s) {
        
        int n = s.size();
        
        int lastValue = findValue(s[n - 1]);
        int finalValue = lastValue;
        
        for(int i = n - 2; i >= 0; i--) {
            
            int curValue = findValue(s[i]);
            if(curValue < lastValue) {
                finalValue = finalValue - curValue;
            } else {
                finalValue = finalValue + curValue;
            }
            lastValue = curValue;
        }
        
        return finalValue;
    }
};