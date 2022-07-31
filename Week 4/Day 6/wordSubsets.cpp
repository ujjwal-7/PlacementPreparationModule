class Solution {
public:
    
    vector<int> calculateFreq(string s) {
        
        vector<int> freq(26, 0);
        
        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> maxFreq(26, 0);
        
        for(int i = 0; i < words2.size(); i++) {
            
            vector<int> tempFreq = calculateFreq(words2[i]);
            
            for(int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], tempFreq[i]);
            } 
        }
        
        vector<string> ans;
        
        for(int i = 0; i < words1.size(); i++) {
            
            vector<int> tempFreq = calculateFreq(words1[i]);
            int flag = 0;
            
            for(int i = 0; i < 26; i++) {
                if(tempFreq[i] < maxFreq[i]) {
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0) {
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};