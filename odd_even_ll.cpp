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
    ListNode* oddEvenList(ListNode* head) {
        if(!head){
            return NULL;
        }
        
        ListNode* oddL=head;
        ListNode* evenL=head->next;

        if(!evenL){
            return oddL;
        }

        bool odd=true;

        ListNode* head_odd=head;
        ListNode* head_even=head->next;

        head=head->next->next;

        while(head){
            if(!odd){
                evenL->next=head;
                evenL=evenL->next;
                odd=true;
            }
            else{
                oddL->next=head;
                oddL=oddL->next;
                odd=false;
            }
            // count++;
            head=head->next;

        }
        evenL->next=NULL;

        oddL->next=head_even;

        return head_odd;


        
    }
};
