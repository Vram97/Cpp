/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        vector<ListNode*> v;
        map<ListNode*,int> mp;
        int count =0;

        while(head){
            // auto it=find(v.begin(),v.end(),head);
            // auto it=mp.find(head);

            if(mp.count(head)>0){
                return head;

            }
            else{
                // v.push_back(head);
                mp.insert(pair<ListNode*,int>(head,count));
            }
            head=head->next;
            count++;
        }
        return NULL;
        
    }
};
