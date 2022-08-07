class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        
        int m = items1.size(), n = items2.size();
        sort(items1.begin(), items1.end());
        sort(items2.begin(), items2.end());
        
        int i = 0, j = 0;
        vector<vector<int>> ret;
        
        while(i < m && j < n) {
            
            if(items1[i][0] == items2[j][0]) {
                ret.push_back({items1[i][0], items1[i][1] + items2[j][1]});
                i++;
                j++;
            } else if(items1[i][0] < items2[j][0]) {
                ret.push_back({items1[i][0], items1[i][1]});
                i++;
            } else {
                ret.push_back({items2[j][0], items2[j][1]});
                j++;
            }
        }
        
        while(i < m) {
            ret.push_back({items1[i][0], items1[i][1]});
            i++;
        }
        
        while(j < n) {
            ret.push_back({items2[j][0], items2[j][1]});
            j++;
        }
        return ret;
    }
};