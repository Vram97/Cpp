/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> mp;
    vector<TreeNode*> vec;
    // int count=0;

    void traverse(TreeNode* head,TreeNode* pt){

        if(head==NULL){
            return;
        }
        mp[head]=pt;

        traverse(head->left,head);
        traverse(head->right,head);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q){
            return NULL;
        }
        traverse(root,nullptr);

        TreeNode* temp = p;
        vec.push_back(p);

        while(temp){
            temp=mp[temp];
            vec.push_back(temp);
        }

        temp=q;
        while(temp){
            auto it=find(vec.begin(),vec.end(),temp);
            if(it!=vec.end()){
                return vec[it-vec.begin()];
            }
            temp=mp[temp];
        }

        return NULL;
    }
};
