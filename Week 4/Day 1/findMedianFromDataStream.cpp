class MedianFinder {
public:
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        int lsize = maxHeap.size();
        int rsize = minHeap.size();
        
        if(lsize == 0) {  // num is the first elemnet of datastream
            
            maxHeap.push(num);
            
        } else if(lsize == rsize) { // push one element in maxHeap for sure
            
            if(num < minHeap.top()) { // num can be pushed to maxHeap(1st half) to maintain order
                maxHeap.push(num);
                
            } else { // Push root of minHeap to maxHeap , push num to 2nd half
                
                int temp = minHeap.top();  // save root of minHeap
                minHeap.pop();     // pop the root of minHeap
                minHeap.push(num);  // push num in minHeap
                maxHeap.push(temp); // push the previous saved root of minHeap in the maxHeap
            }
        } else { // we assume that maxHeap can be larger than Minheap by a max of 1 element only
            
            if(minHeap.size() == 0) {
                
                if(num > maxHeap.top()) { // push num to 2nd half

                    minHeap.push(num);
                } else { // push num to 1st half

                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(temp);

                }
            } else if(num >= minHeap.top()) { // push the element directly in minHeap 2nd half
                
                minHeap.push(num);
            } else {
                
                if(num < maxHeap.top()) { // push num to 1st half
                    
                    int temp = maxHeap.top(); // save root of maxHeap
                    maxHeap.pop(); // pop root of maxHeap
                    maxHeap.push(num); // push num to maxheap
                    minHeap.push(temp); // push previous saved root of maxheap to minheap
                    
                } else { // push num to 2nd half
                    minHeap.push(num);
                }
            }
            
        }
    }
    
    double findMedian() {
        
        int lsize = maxHeap.size();
        int rsize = minHeap.size();
        
        if(lsize  > rsize)
            return double(maxHeap.top());
        else
            return (double(maxHeap.top()) + double(minHeap.top())) / 2;
    }        
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */