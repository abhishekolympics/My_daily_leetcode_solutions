//WATCH THIS VIDEO https://www.youtube.com/watch?v=vQIiUWofWw8
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL){
            return res;
        }
        queue <TreeNode*> q;
        q.push(root); 
        q.push(NULL);
        vector<int>tt;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node != NULL)
            {
                cout<<node->val<<" ";
                tt.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            else if(!q.empty())
            {
                res.push_back(tt);
                tt.clear();
                cout<<endl;
                q.push(NULL);
            }
            else if(q.empty())
            {
                res.push_back(tt);
                tt.clear();
                cout<<endl;
            }
        }
        return res;
    }
};