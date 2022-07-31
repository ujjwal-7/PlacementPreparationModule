class Solution {
public:
    bool check(TreeNode* root, TreeNode* minValue, TreeNode* maxValue) {
        
        if(root == NULL)
            return true;
        
        if(minValue && root->val <= minValue->val || maxValue && root->val >= maxValue->val)
            return false;
        
        return check(root->left, minValue, root) && check(root->right, root, maxValue);
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        TreeNode *minValue = NULL, *maxValue = NULL;
        return check(root, minValue, maxValue);
        
    }
};