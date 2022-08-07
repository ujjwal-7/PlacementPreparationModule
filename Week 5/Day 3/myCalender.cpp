class MyCalendar {
public:
    unordered_map<int, int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        for(auto it: mp) {
            
            if(it.first <= start && start < it.second || it.first > start && end > it.first) {
               
                return false;
            }
        }
        
        mp[start] = end;
        return true;
    }
};

