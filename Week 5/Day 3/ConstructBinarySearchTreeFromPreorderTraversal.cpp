class Solution {
public:
    
    TreeNode* solve(vector<int>& preorder, int& idx, int parent, int n) {
        
        if (idx == n || preorder[idx] > parent)
            return NULL;
        
        int current = preorder[idx++];
        
        TreeNode *temp = new TreeNode(current);
        
        temp->left = solve(preorder, idx, current, n);
        temp->right = solve(preorder, idx, parent, n);
        
        return temp;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n = preorder.size();
        int idx = 0;
        int parent = INT_MAX;
        return solve(preorder, idx, parent, n);
        
    }
};