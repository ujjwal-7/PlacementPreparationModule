class Solution {
public:
    
    bool isMatching(char open, char close) {
        
        if(open == '(' && close == ')')
            return true;
        
        if(open == '{' && close == '}')
            return true;
        
        if(open == '[' && close == ']')
            return true;
        
        return false;
    }
    
    bool isValid(string s) {
        
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                
                st.push(s[i]);
                
            } else if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                
                if(st.empty() == true)
                    return false;
                
                char open = st.top();
                st.pop();
                
                if(!isMatching(open, s[i]))
                    return false;
            }
        }
        
        return st.empty();
    }
};