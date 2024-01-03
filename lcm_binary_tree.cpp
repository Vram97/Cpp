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

    void traverse(TreeNode* head,TreeNode* pt, int &stop,const TreeNode* const p, const TreeNode* const q){

        if(head==NULL || stop==2){
            return;
        }
        mp[head]=pt;

        if(head==p || head==q){
            stop++;
        }

        traverse(head->left,head,stop,p,q);
        traverse(head->right,head,stop,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q){
            return NULL;
        }
        int stop=0;
        traverse(root,nullptr,stop,p,q);

        TreeNode* temp = p;
        vec.emplace_back(p);

        while(temp){
            temp=mp[temp];
            vec.emplace_back(temp);
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
