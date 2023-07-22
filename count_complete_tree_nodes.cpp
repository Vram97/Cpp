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
    int traverse(TreeNode* head,int cnt){
        if(!head){
            return cnt;
        }
        cnt++;

        cnt=traverse(head->left,cnt);
        cnt=traverse(head->right,cnt);

        return cnt;

    }
    int countNodes(TreeNode* root) {
    
        return traverse(root,0);
        
    }
};
