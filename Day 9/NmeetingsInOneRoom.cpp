class Solution
{
    public:
    
    int maxMeetings(int start[], int end[], int n)
    {
       
        
        if(n < 2)
            return n;
            
        vector<vector<int>> temp;
        
        for(int i = 0; i < n; i++)
            temp.push_back({end[i], start[i]});
            
        sort(temp.begin(), temp.end());
            
        int count = 1;
        vector<int> ans = temp[0];
        
        for(int i = 1; i < temp.size(); i++) {
            
            if(ans[0] < temp[i][1]) {
                
                count++;
                ans = temp[i];
                
            } else {
                
                if(ans[0] > temp[i][0])
                    ans = temp[i];
            }
            
        }
        
        return count;
    }
};