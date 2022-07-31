class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> temp;
        string helper = "";
        
        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] != ' ') {
                helper += s[i];
            } else {
                if(helper != "") {
                    temp.push_back(helper); 
                }
                helper = "";
            }
        }
        
        if(helper != "")
            temp.push_back(helper);
        
        string result = "";
        
        for(int i = temp.size() - 1; i > 0; i--) {
            
            result += temp[i] + " ";
        }
        
        result += temp[0];
        
        
        return result;
    }
};