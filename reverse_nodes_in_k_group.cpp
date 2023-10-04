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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(k==1 || k==0){
            return head;
        }

        vector<ListNode*> vec;

        while(head){
            vec.emplace_back(head);
            head=head->next;
        }

        const int sz=vec.size();

        int i=0;
        int t=0;
        const int times=sz/k;

        while(t<times){

            if(t==times-1){
                if(i+k<sz){
                    vec[i]->next=vec[i+k];
                }
                else{
                    vec[i]->next=NULL;
                }
                
            }
            else{
                vec[i]->next=vec[i+2*k-1];
            }

            for(int y=k;y>1;y--){
                vec[i+y-1]->next=vec[i+y-2];
            }

            i+=k;
            t++;
        }

        return vec[k-1];
        
    }
};
