class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        set<char> store;
        int start=0,end=0;
        int len=0;
        
        while(end<s.size())
        {
            
            if(store.find(s[end])==store.end())
            {
                store.insert(s[end]);  
                
            }
            else{
                if(store.find(s[end])!=store.end()){
                    store.erase(s[start]);
                    start++;
                }
                store.insert(s[end]);  
            }
            
            len=max(len,end-start+1);
               end++;
        }
        
        return len;
        
    }
};