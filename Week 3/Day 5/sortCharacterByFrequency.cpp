class Solution {
public:
    string frequencySort(string s) {
        
        /* TC O(NlogN) SC O(N)
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }
        
        string ans = "";
        
        while(pq.size() > 0) {
            
            int count = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            
            for(int i = 1; i<= count; i++)
                ans += ch;
            
        }
        
        return ans;
        */
        
        
        // TC O(N)
        unordered_map<char, int> mp;
        
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        
        vector<vector<char>> temp(s.size() + 1);
        
        for(auto it : mp) {
            
            temp[it.second].push_back(it.first);
        }
        
        string ans = "";
        
        for(int i = s.size(); i >= 0; i--) {
            
            for(int j = 0; j <temp[i].size(); j++) {
                
                /*for(int k = 1; k <= i; k++) {
                    ans += temp[i][j];
                }*/
                
                //or
                
                ans += string(i, temp[i][j]);
            }
        }
        
        return ans;
        
    }
};