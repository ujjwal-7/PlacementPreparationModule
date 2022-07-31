class Solution {
public:
    void flatten(TreeNode* root) {
        
        if(root == NULL)
            return;
        
        TreeNode* cur = root;
        
        while(cur != NULL) {
            
            if(cur->left != NULL) {
                
                TreeNode* last = cur->left;
                
                while(last->right != NULL) {
                    
                    last = last->right;
                }
                
                last->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            
            cur = cur->right;
        }
        
        
    }
};