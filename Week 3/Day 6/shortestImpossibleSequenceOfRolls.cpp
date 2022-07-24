class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        
        vector<int> ans;
        unordered_set<int> s;
        
        for(int i = 0; i < rolls.size(); i++) {
            
            s.insert(rolls[i]);
            
            if(s.size() == k) {
                
                ans.push_back(rolls[i]);
                s.clear();
            }
        }
        
        for(char i = 1; i <= k; i++) {
            
            if(s.count(i) == 0) {
                
                ans.push_back(i);
                return ans.size();
            }
        }
        
        return ans.size();
    }
};