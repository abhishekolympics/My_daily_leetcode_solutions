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
    
    TreeNode* buildTree(vector<int>& preorder, int pre_start,int pre_end, vector<int>& inorder, int in_start, int in_end, unordered_map<int,int>& mp)
    {
        if(pre_start > pre_end || in_start > in_end) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int t=mp[preorder[pre_start]];
        int nums_left=t-in_start;

        root->left = buildTree(preorder,pre_start+1,pre_start+nums_left,inorder,in_start,t-1,mp);
        root->right = buildTree(preorder,pre_start+nums_left+1,pre_end,inorder,t+1,in_end,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int,int>mp;
        int i=inorder.size(),s=preorder.size();

        for(int i=0;i<s;i++)
        {
            mp[inorder[i]]=i;
        }

        TreeNode* root = buildTree(preorder,0,s-1,inorder,0,i-1,mp);
        return root;
    } 
};