class Solution {
public:
    
    int findPosition(vector<int>& inorder, int element, int n) {
        
        for(int i = 0; i < n; i++) {
            
            if(inorder[i] == element)
                return i;
        }
        return -1;
    }
    
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int& ind, int inS, int inE, int n) {
       
        if(ind >= n || inS > inE) {
            return NULL;
        }
        
        int element = preorder[ind++];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(inorder, element, n);
        
        root->left = createTree(preorder, inorder, ind, inS, position - 1, n);
        root->right = createTree(preorder, inorder, ind, position + 1, inE, n);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        int preOrderIndex = 0;
        return createTree(preorder, inorder, preOrderIndex, 0, n - 1, n);    
    }
};