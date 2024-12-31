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
    TreeNode* traverse(unordered_map<int,int> &mp,vector<int> &preorder,int &index,const int &len,int start,int end){
        if(start>end){
            return NULL;
        }
        // std::cout<<index<<std::endl;
        TreeNode* root=new TreeNode(preorder[index++]);

        int mid=mp[root->val];

        root->left=traverse(mp,preorder,index,len,start,mid-1);
        root->right=traverse(mp,preorder,index,len,mid+1,end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        const int len=preorder.size();
         
        if(len==0){
            return NULL;
        }
        for(int i=0;i<len;i++){
            mp[inorder[i]]=i;
        }
        int index=0;
        return this->traverse(mp,preorder,index,len,0,len-1);

    }
};

