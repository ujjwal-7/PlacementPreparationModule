class Solution {
public:
    char repeatedCharacter(string s) {
        
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }
        
        int first = INT_MAX, last = INT_MAX;
        char ans;
        
        for(auto it: mp) {
            
            if(it.second.size() >= 2) {
                
                if(it.second[1] < last) {
                    
                    ans = it.first;
                    last = it.second[1];
                    first = it.second[0];
                    
                }
                
            }
        }
        
        return ans;
    }
};