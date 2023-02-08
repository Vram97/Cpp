class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> v;

        while(true){
            v.push_back(head);
            head=head->next;
            if(head==nullptr){break;}
        }

        int len =v.size();
        if(len-n == 0 && len>1){
            return v[1];
        }
        else if(len==1){
            return nullptr;
        }
        v[len-1-n]->next=v[len-n]->next;

        return v[0];
    }
};
