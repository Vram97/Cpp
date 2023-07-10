/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    unordered_map<int,vector<Node*>> mp;

    void traverse(Node* head,int index){
        if(!head){
            return;
        }

        mp[index].push_back(head);

        traverse(head->left,index+1);
        traverse(head->right,index+1);
    }

    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }

        traverse(root,0);

        for(auto x=mp.begin();x!=mp.end();x++){
            int sz=x->second.size();
            if(sz>1){
                for(int i=0;i<sz-1;i++){
                    x->second[i]->next=x->second[i+1];
                }
            }
        }
        return root;

    }
};
