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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result=new ListNode(0);
        ListNode* start=result;
        int balance=0;
        bool bl=true;

        while(true){
            int sum=0;

            if(l1){
                sum=l1->val;
                l1=l1->next;
                bl=false;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
                bl=false;
            }
            if(bl==true){
                break;
            }
            sum+=balance;

            if(sum>9){
                balance=1;
                start->next=new ListNode(sum%10);
            }
            else{
                balance=0;
                start->next=new ListNode(sum);
            }

            
            start=start->next;

            bl=true;

        }
        if(balance>0){
            start->next=new ListNode(balance);
        }

        return result->next;
        
    }
};
