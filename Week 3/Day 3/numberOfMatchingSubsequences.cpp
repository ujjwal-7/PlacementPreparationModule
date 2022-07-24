class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < s.size(); i++) {
            
            mp[s[i]].push_back(i);
        }
        
        int count = 0;
        for(int i = 0; i < words.size(); i++) {
            
            string cur = words[i];
            int prev = -1;
            
            for(int j = 0; j < cur.size(); j++) {
                
                auto it = upper_bound(mp[cur[j]].begin(), mp[cur[j]].end(), prev);
                
                if(it == mp[cur[j]].end())
                    break;
                
                prev = *it;
                if(j == cur.size() - 1)
                    count++;
                
            }
        }
        return count;
    }
};