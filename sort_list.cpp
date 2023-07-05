/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head){
            return head;
        }

        vector<ListNode*> node_vec;

        while(head){
            node_vec.push_back(head);

            head=head->next;
        }

        sort(node_vec.begin(),node_vec.end(),[](ListNode* a,ListNode* b){return a->val<b->val;});

        for(int i=0;i<node_vec.size()-1;i++){
            node_vec[i]->next=node_vec[i+1];
        }
        node_vec.back()->next=NULL;

        return node_vec[0];
        
    }
};
