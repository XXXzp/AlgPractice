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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){return head;}
        ListNode* front = new ListNode(-1);
        front->next = head;
        ListNode* nodeFast = front;
        ListNode* node = front; 
        for(int i =0;i<n;i++){
            nodeFast = nodeFast->next;
        }
        while(nodeFast->next!=NULL){
            nodeFast = nodeFast->next;
            node = node->next;
        }
        ListNode* to_delete = node->next;
        node->next = node->next->next;
        delete to_delete;      
        return front->next;
    }
};