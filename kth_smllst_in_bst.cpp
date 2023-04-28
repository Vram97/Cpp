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
    void traverse(TreeNode* t,int el,bool stat){
        
        if(!t || (stat==true && count>=el)){
            return;
        }
        v.emplace_back(t->val);

        count++;

        traverse(t->left,el,false);
        if(t==org){
            stat=true;
        }

        traverse(t->right,el,stat);

    }

    vector<int> v;
    int count=0;
    TreeNode* org;

    int kthSmallest(TreeNode* root, int k) {
        if(root){
            org=root;
        }
        traverse(root,k,false);
        sort(v.begin(),v.end());
        return v[k-1];
        
    }
};
