class Solution {
public:
    void pushConnect(int value){
        if(!v.empty()){
            v.back()->right=new TreeNode(value);
            v.push_back(v.back()->right);
        }
        else{
            v.emplace_back(new TreeNode(value));
        }
    }
    void traverse(TreeNode* nd){
        if(nd==NULL){
            return ;
        }
        // st->right=new TreeNode(nd->val);
        // cout<<st->val<<endl;
        // cout<< nd->val;
        // v.push_back(TreeNode(nd->val));

        // st->left=NULL;
        // st=st->right;

        pushConnect(nd->val);

        traverse(nd->left);
        traverse(nd->right);

    }
    void flatten(TreeNode* root) {
        if(root){
            // ll->val=root->val;
            

            // TreeNode* st=ll;

            traverse(root);
            root=v[0];
            if(v.size()>1){
                cout<<root->right->val<<endl;
            }
            
            return;
            // root=ll->right;
            // cout<<root->right->val;
            for(auto x:v){
                cout<<x->val<<endl;
            }
        }
        else{
            return;
        }


        
        // cout<<root->right->val<<endl;
    }
private:
    // TreeNode* ll = new TreeNode();
    vector<TreeNode*> v;
};
