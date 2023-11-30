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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }

        ListNode* og_head=lists[0];
        while(!og_head){
            lists.erase(lists.begin());
            if(lists.empty()){
                return NULL;
            }
            else{
                og_head=lists[0];

            }
        }

        for(int i=1;i<lists.size();i++){

            ListNode* curr_head=lists[i];

            if(!curr_head){
                continue;
            }

            if(curr_head->val<=og_head->val){
                ListNode* temp=new ListNode(curr_head->val,og_head);
                og_head=temp;
                curr_head=curr_head->next;
            }
            
            ListNode* curr_og_head=og_head;
            
            while(curr_head){
                // cout<<curr_head->val<<endl;
                if(curr_og_head->next){
                    if(curr_head->val<=curr_og_head->next->val){
                        ListNode* temp=new ListNode(curr_head->val,curr_og_head->next);
                        curr_og_head->next=temp;
                        curr_head=curr_head->next;                       
                    }
                    curr_og_head=curr_og_head->next;
                }
                else{
                    curr_og_head->next=new ListNode(curr_head->val);
                    curr_head=curr_head->next;
                    curr_og_head=curr_og_head->next;
                }
                
            }
        }
        // cout<<"FInal"<<endl;
        // cout<<og_head->val<<endl;

        return og_head;



    }
};
