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
    vector<int> v;
    int count=0;

    ListNode* realHead;

    Solution(ListNode* head) {
        realHead=head;

        while(head){
            v.push_back(head->val);
            count++;
            head=head->next;
        }
    }
    
    int getRandom() {
        // int x=rand()%count;
        // int cnt=0;
        // ListNode* head2=realHead;

        // while(cnt!=x){

        // }
        return v[rand()%count];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

