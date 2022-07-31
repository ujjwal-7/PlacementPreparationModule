class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
        if(root == NULL)
            return NULL;
        
        if(root->val == p->val || root->val == q->val)
            return root;
        
        TreeNode* leftSearch = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSearch = lowestCommonAncestor(root->right, p, q);
        
        if(leftSearch != NULL && rightSearch != NULL)
            return root;
        
        return leftSearch != NULL ? leftSearch : rightSearch;
    }
};