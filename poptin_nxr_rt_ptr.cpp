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
    void traverse(Node* &nd, int ind,unordered_map<int,vector<Node*>>& ump){
        if(nd==NULL){
            return;
        }
        if(ump.find(ind)!=ump.end()){
            ump[ind].back()->next=nd;
        }
        ump[ind].emplace_back(nd);
        traverse(nd->left,ind+1,ump);
        traverse(nd->right,ind+1,ump);

    }
    Node* connect(Node* root) {
        unordered_map<int,vector<Node*>> mp;

        traverse(root,0,mp);


        return root;
    }
};
