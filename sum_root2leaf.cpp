class Solution {
public:
    void traverse(TreeNode* t,bool stat,int sum){
        // static int count = 0;
        if(t==NULL){
            if(stat==true){
                total+=sum;
            }
            // count++;
            return ;
        }

        sum=sum*10 + t->val;
        // cout<<sum<<endl;
        traverse(t->left,false,sum);

        if(t->left){
            stat=false;
        }
        else{
            stat=true;
        }

        traverse(t->right,stat,sum);
    }
    int sumNumbers(TreeNode* root) {
        traverse(root,false,0);
        // return count/2;
        return total;
    }
private:
    int total = 0;
    int sum = 0;
    vector<int> v;
};

