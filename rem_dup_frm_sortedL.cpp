class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int>seen;
        map<int,int>repeat;

        ListNode* head2(head);
        // ListNode* head3(head);
        ListNode* prev(head);

        while(head){
            if(seen.count(head->val)>0){
                seen[head->val]++;
                // cout<<seen[head->val]<<endl;
                prev->next=head->next;
            }
            else{
                seen[head->val]=1;
                prev=head;
            }
            // prev=head;
            head=head->next;
        }
        prev= new ListNode(-101,head2);
        ListNode* prev_fin=prev;
        while(head2){

            // cout<<head2->val<<endl;
            if(seen[head2->val]>1){
                // cout<<head2->val<<endl;
                prev->next=head2->next;
            }
            else{prev=head2;}
            head2=head2->next;
        }
        return prev_fin->next;
    }
};
