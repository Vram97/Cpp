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
class BSTIterator {
public:
    TreeNode* curr;
    vector<TreeNode*> vec;
    int sz=0;
    int index=-1;

    void traverse(TreeNode* rt){
        if(rt==NULL){
            return;
        }
        vec.emplace_back(rt);

        traverse(rt->left);
        traverse(rt->right);
    }

    BSTIterator(TreeNode* root) {
        traverse(root);
        sort(vec.begin(),vec.end(),[](TreeNode* a,TreeNode* b){return a->val < b->val;});
        sz=vec.size();
        curr=new TreeNode(INT_MIN);

    }
    
    int next() {
        if(index==sz-1){
            return 0;
        }

        index++;
        // cout<<index<<endl;
        curr=vec[index];
        return curr->val;
    }
    
    bool hasNext() {
        if(index!=sz-1){
            return true;
        }
        return false;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
