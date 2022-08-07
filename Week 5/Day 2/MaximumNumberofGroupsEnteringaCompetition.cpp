class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        
        int n = grades.size();
        int prevSize = 1, groups = 1;
        
        int i = 1;
        while(i < n) {
            
            if(prevSize < n - i) {
                
                prevSize += 1;
                groups += 1;
            } else {
                break;
            }
            i += prevSize;
        }
        return groups;
    }
};