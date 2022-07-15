class Solution {
public:
    
    int findPosition(vector<int>& inorder, int element, int n) {
        
        for(int i = 0; i < n; i++) {
            
            if(inorder[i] == element)
                return i;
        }
        return -1;
    }
    
    TreeNode* createTree(vector<int>& postorder, vector<int>& inorder, int& ind, int inS, int inE, int n) {
       
        if(ind < 0 || inS > inE) {
            return NULL;
        }
        
        int element = postorder[ind--];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(inorder, element, n);
        
        root->right = createTree(postorder, inorder, ind, position + 1, inE, n);
        root->left = createTree(postorder, inorder, ind, inS, position - 1, n);
       
        return root;   
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = postorder.size();
        int postOrderIndex = n - 1;
        return createTree(postorder, inorder, postOrderIndex, 0, n - 1, n);    
    }
};