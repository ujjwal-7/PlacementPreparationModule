class Solution {
public:
    
    void findNextSmallerToLeft(vector<int>& heights, vector<int>& nextSmallerToLeft, int n) {
        
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                nextSmallerToLeft[i] = -1;
            } else {
                nextSmallerToLeft[i] = st.top();
            }
            
            st.push(i);
        }
    }
    
    void findNextSmallerToRight(vector<int>& heights, vector<int>& nextSmallerToRight, int n) {
        
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--) {
            
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                nextSmallerToRight[i] = n;
            } else {
                nextSmallerToRight[i] = st.top();
            }
            
            st.push(i);
        }
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> nextSmallerToLeft(n), nextSmallerToRight(n);
        
        findNextSmallerToLeft(heights,  nextSmallerToLeft, n);
        findNextSmallerToRight(heights,  nextSmallerToRight, n);
        
        int area = 0;
        for(int i = 0; i < n; i++) {
            
        area = max(area, (nextSmallerToRight[i] - nextSmallerToLeft[i] - 1) * heights[i]);
        }
        
        return area;
    }
};