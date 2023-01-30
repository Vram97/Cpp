class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // ListNode* head=list2;
        // ListNode* temp;
        // ListNode* prev;
        // prev=new ListNode(-111,list2);

        // while(list1){
        //     if(list1->val>=list2->val && list1->val<list2->next->val){
        //         temp=list2->next;
        //         list2->next=new ListNode(list1->val,temp);
        //         // list2->next->next=temp;
        //         prev=list2;
        //         list2=list2->next;

        //     }
        //     else if(list1->val>list2->next->val){
        //         prev=list2;
        //         list2=list2->next;
        //     }
        //     else{
        //         prev->next=new ListNode(list2->val,list2);
        //         // prev->next->next=list2;
        //     }
        //     list1=list1->next;
        // }
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode* adder;
        ListNode* base;
        ListNode* head;
        ListNode* temp;

        if(list1->val<=list2->val){
            base=list1;
            adder=list2;
            head=base;
        }
        else{
            base=list2;
            adder=list1;
            head=base;
        }

        while(adder){
            if(base->next){
                if(adder->val>=base->val && adder->val<base->next->val){
                    temp=base->next;
                    base->next=new ListNode(adder->val,temp);
                    base=base->next;
                    adder=adder->next;
                }
                else{
                    base=base->next;
                }
            }
            else{
                base->next=new ListNode(adder->val,NULL);
                base=base->next;
                adder=adder->next;
            }
            
        }
        return head;
    }
};
