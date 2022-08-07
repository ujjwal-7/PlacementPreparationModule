class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        
        int n = tasks.size();
        long long dayNumber = 0;
        
        unordered_map<int, long long> mp;
        
        for(int i = 0; i < n; i++) {
            
            if(mp.find(tasks[i]) == mp.end()) {
                
                mp[tasks[i]] = dayNumber;
                dayNumber += 1;
            } else {
                
                long long diff = dayNumber - mp[tasks[i]];
                
                if(diff >= space + 1) {
                    mp[tasks[i]] = dayNumber;
                    dayNumber += 1;
                } else {
                    
                    int rem = space + 1 - diff;
                    dayNumber += rem;
                    mp[tasks[i]] = dayNumber;
                    dayNumber += 1;
                }
                
                
            }
        }
        return dayNumber;
    }
};