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
    void reorderList(ListNode* head) {
        if(!head){
            return;
        }

        int count=0;
        int i=0;
        int s=0;
        vector<ListNode*> v;
        bool sw=false;
        // ListNode* BN= new ListNode(0);
        ListNode* ln=head;

        while(ln){
            v.push_back(ln);
            count++;
            ln=ln->next;
        }
        // cout<<count<<endl;
        if(count<3){
            return ;
        }

        while(s!=count-1){
            // cout<<head->val<<endl;
            if(sw){
                head->next=v[i];
            }
            else{
                head->next=v[count-1-i];
                i++;
            }
            s++;
            sw=!sw;
            head=head->next;

        }
        head->next=NULL;

    }
};
