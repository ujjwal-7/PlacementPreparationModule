class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
    	
    	
        sort(arr, arr + n);
        sort(dep, dep + n);
        
        int i = 1, j = 0, platforms = 1, count = 1;
        
        while(i < n && j < n) {
            
            if(arr[i] <= dep[j]) {
                
                count++;
                i++;
                platforms = max(platforms, count);
                
            } else {
                
                count--;
                j++;
            }
        }
        
        return platforms;
    }
};