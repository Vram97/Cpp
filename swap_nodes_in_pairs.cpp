class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* ln=head;

        if(head->next){
            ln=head->next;
        }
        else{
            return head;
        }

        ListNode* prev=NULL;

        while(head && head->next){

            // cout<<head->val<<endl;
            ListNode* temp=head->next;
            head->next=head->next->next;
            temp->next=head;
            // head=temp;
            if(prev){
                prev->next=temp;
            }

            prev=head;

            head=temp->next->next;

            // cout<<head->next->val<<endl;
            
        }

        return ln;
    }

};
