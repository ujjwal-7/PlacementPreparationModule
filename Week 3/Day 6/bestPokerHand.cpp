class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        
        int isSame = true;
        
        for(int i = 0; i <suits.size() - 1; i++) {
            
            if(suits[i] != suits[i + 1]) {
                isSame = false;
                break;
            }
                
        }
        
        if(isSame == true)
            return "Flush";
        
        map<int, int> mp;
        
        for(int i = 0; i < ranks.size(); i++) {
            
            mp[ranks[i]]++;
            
        }
        
        for(auto it : mp) {
            
            if(it.second >= 3)
                return "Three of a Kind";
            
            if(it.second == 2)
                return "Pair";
        }
        
        return "High Card";
        
    }
};