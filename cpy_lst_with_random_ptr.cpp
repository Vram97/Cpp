Shivaram Srikanth
Shivaram Srikanth
Apr 13, 2023 23:19
C++
Runtime11 ms
Beats
46.58%
Memory11.3 MB
Beats
31.99%
Click the distribution chart to view more details
Notes
Related Tags
0/5

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*> mp;
        Node* temp;
        Node* head_org=head;
        Node* prev=head;

        temp=new Node(prev->val);
        // cout<<prev->val<<endl;
        mp[prev]=temp;

        head=head->next;

        while(head){
            temp=new Node(head->val);
            mp[prev]->next=temp;
            mp[head]=temp;

            prev=prev->next;
            head=head->next;

        }

        for(auto i=mp.begin();i!=mp.end();i++){
            temp=i->first->random;
            if(temp){
                mp[i->first]->random=mp[i->first->random];
            }
            // cout<<i->second->val<<endl;
        }

        return mp[head_org];
        

        // while(head->next){
        //     Node* temp = new Node(prev->val);
        //     temp->next=head;
        //     mp[prev]=temp;
        //     head=head->next;
        // }
    }
};
