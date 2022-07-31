bool isPossible(vector<int> &stalls, int mid, int k, int n) {
    
    int lastIndex = stalls[0];
    int cow = 1;
    
    for(int i = 1; i < n; i++) {
        
        if(stalls[i] - lastIndex >= mid) {
            cow++;
            lastIndex = stalls[i];
            if(cow >= k)
                return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    
    int i = 1, j = stalls[n - 1] - stalls[0];
    int minDist;
    while(i <= j) {
        
        int mid = i + (j - i) / 2;
        
        if(isPossible(stalls, mid, k, n)) {
            minDist = mid;
             i = mid + 1;
            
        } else {
            j = mid - 1;
           
        }
    }
    
    return minDist;
    
}