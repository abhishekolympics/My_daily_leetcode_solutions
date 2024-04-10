//WATCH THIS VIDEO https://www.youtube.com/watch?v=G5c1wM3Kpuw

class Solution {
public:
    
    TreeNode* formTree(vector<int>& preorder, vector<int>& inorder, int start, int end, unordered_map<int,int>& mp,int& idx)
    {
        if(start > end) return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx]);
        int i = mp[preorder[idx]];
        idx++;

        root->left = formTree(preorder, inorder, start, i - 1, mp, idx);
        root->right = formTree(preorder, inorder, i + 1, end, mp, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int,int>mp;
        int s = preorder.size(), idx=0;

        //use this map to traverse faster in recursive calls
        for(int i=0;i<s;i++)
        {
            mp[inorder[i]]=i;
        }

        return formTree(preorder,inorder,0,s-1,mp,idx);
    } 
};
