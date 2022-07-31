class Solution {
public:
    
    void helper(TreeNode* root, int &maxDiff, int minVal, int maxVal) {
        
        if(root == NULL) {
            return;
        }
        
        maxVal = max(maxVal, root->val);
        minVal = min(minVal, root->val);
        
        maxDiff = max(maxDiff, maxVal - minVal);
        
        helper(root->left, maxDiff, minVal, maxVal);
        helper(root->right, maxDiff, minVal, maxVal);
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        int maxDiff = 0;
        helper(root, maxDiff, INT_MAX, INT_MIN);
        return maxDiff;
        
    }
};