class NumberContainers {
public:
    
    unordered_map<int, int> mp;
    map<int, set<int>> smallestIndex;
    
    NumberContainers() {
        
        
        
    }
    
    void change(int index, int number) {
        
        if(mp.find(index) == mp.end()) {
            
            mp[index] = number;
            smallestIndex[number].insert(index);
        } else {
            
            smallestIndex[mp[index]].erase(index);
            mp[index] = number;
            smallestIndex[number].insert(index);
        }
    }
    
    int find(int number) {
        
        if(smallestIndex.find(number) == smallestIndex.end() || smallestIndex[number].size() == 0)
            return -1;
        
        return *smallestIndex[number].begin();
        
    }
};
