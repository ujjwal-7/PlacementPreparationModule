/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        int width = 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        while(!q.empty()) {
            
            int n = q.size();
            
            int start = q.front().second;
            int end = q.back().second;
            
            width = max(width, end - start + 1);
            
            for(int i = 0; i < n; i++) {
                
                TreeNode* cur = q.front().first;
                
                int index = q.front().second - start;
                
                q.pop();
                
                if(cur->left != NULL) {
                    
                    q.push({cur->left, (long long)2*index});
                }
                
                if(cur->right != NULL) {
                    
                    q.push({cur->right, (long long)2*index + 1});
                }
                
            }
            
        }
        
        return width;
    }
};