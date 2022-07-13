class Solution {
public:
    int depth(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        return 1 + max(depth(root->left), depth(root->right));
        
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(root == NULL)
            return {};
        
        int d = depth(root);
        
        vector<vector<int>> ans(d);
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            
            int n = q.size();
            vector<int> level;
            
            while(n--) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                level.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
                
            }
            
             ans[d-1] = level;
             d--;
        }
        
        return ans;
    }
};