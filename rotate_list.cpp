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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || k==0){
            return head;
        }

        unordered_map<int, ListNode*> mp;
        int ind=0;
        ListNode* temp=head;

        while(temp){
            
            mp[ind]=temp;
            temp=temp->next;
            ind++;
        }

        if(ind==1){
            return head; 
        }

        k=k%ind;

        // ind-=1;
        if(k==0){
            return head;
        }

        mp[ind-1]->next=mp[0];
        mp[ind-1-k]->next=NULL;

        // cout<<"Before loop"<<endl;
        // for(int i=0;i<k;i++){
        //     cout<<ind-i<<endl;
        //     mp[ind-i]->next=prev;
        //     prev=mp[ind-i];
        // }

        // mp[ind-k]->next=NULL;
        // cout<<ind-k<<endl;
        return mp[ind-k];
        
    }
};
