class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        
        for(int i = 0; i < words.size(); i++) {
            
            unordered_map<char, char> mp;
            string temp = words[i];
            int flag = 0;
            
            for(int j = 0; j < pattern.size(); j++) {
                
                if(mp.find(pattern[j]) == mp.end()) {
                    
                    for(auto it : mp) {
                        if(it.second == temp[j]) {
                            flag = 1;
                            break;
                        }
                    }
                    
                    if(flag == 1)
                        break;
                    
                    mp[pattern[j]] = temp[j];
                    
                } else {
                    
                    if(mp[pattern[j]] != temp[j]) {
                        flag = 1;
                        break;
                    } 
                }
            }
            
            if(flag == 0)
                ans.push_back(temp);
        }
        return ans;
    }
};